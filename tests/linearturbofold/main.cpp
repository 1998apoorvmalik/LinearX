#include <iostream>
#include <string>

#include "./../../sequence/multi_seq.hpp"
#include "./../../turbofold/turbofold.hpp"

using namespace std;

// example run: ./main ./test_seqs/sample1.fasta 0 3 1 1 1

MultiSeq read_msa_file(const std::string& filePath, std::unordered_map<char, int>* encoding_scheme = nullptr) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filePath);
    }

    MultiSeq mseq;
    std::string line, currentName, currentDotBracket;

    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;  // Skip empty lines
        }
        if (line[0] == '>') {  // Header line
            if (!currentName.empty() && !currentDotBracket.empty()) {
                mseq.add_sequence(Seq(currentName, currentDotBracket, mseq.size(), encoding_scheme));
                currentDotBracket.clear();
            }
            currentName = line.substr(1);  // Remove '>'
        } else {
            currentDotBracket = line;  // Dot-bracket line
        }
    }

    // Add the last sequence
    if (!currentName.empty() && !currentDotBracket.empty()) {
        mseq.add_sequence(Seq(currentName, currentDotBracket, mseq.size(), encoding_scheme));
    }

    return mseq;
}

int main(int argc, char* argv[]) {
    // Check if the number of arguments is correct (must be an even number for name-sequence pairs)
    if (argc != 7) {
        std::cerr << "Usage: " << argv[0]
                  << " <msa_file_path> <energy_params> <num_iterations> <use_lazy_outside> <use_prev_outside_score> "
                     "<shrink_beam> \n";
        return EXIT_FAILURE;
    }

    std::string msaFilePath = argv[1];
    EnergyParamsType energy_params = std::stoi(argv[2]) == 0 ? EnergyParamsType::VIENNA : EnergyParamsType::BL_STAR;
    int num_itr = std::stoi(argv[3]);
    bool use_lazy_outside = std::stoi(argv[4]);
    bool use_prev_outside_score = std::stoi(argv[5]);
    int shrink_beam = std::stoi(argv[6]);

    std::cerr << "Arguments:\n";
    std::cerr << "msa_file_path: " << msaFilePath << "\n";
    std::cerr << "energy_params: " << energy_params << "\n";
    std::cerr << "num_itr: " << num_itr << "\n";
    std::cerr << "use_lazy_outside: " << use_lazy_outside << "\n";
    std::cerr << "use_prev_outside_score: " << use_prev_outside_score << "\n";
    std::cerr << "shrink_beam: " << shrink_beam << "\n";

    try {
        // Read MSA file and generate MultiSeq
        MultiSeq mseq = read_msa_file(msaFilePath, &VIENNA_NUC_ENCODING_SCHEME);

        double alignment_pruning_threshold = -DEVIATION_THRESHOLD * (use_lazy_outside && use_prev_outside_score ? 1 : 1);
        double folding_pruning_threshold = -DEVIATION_THRESHOLD * (use_lazy_outside && use_prev_outside_score ? 1 : 1);

        std::cerr << "Alignment Pruning Threshold: " << alignment_pruning_threshold << "\n";
        std::cerr << "Folding Pruning Threshold: " << folding_pruning_threshold << "\n\n";

        LinearTurboFold ltf(&mseq, energy_params, num_itr, use_lazy_outside, use_prev_outside_score, shrink_beam, 0.3,
                            alignment_pruning_threshold, folding_pruning_threshold);
        ltf.run();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;

    // MultiSeq mseq;
    // mseq.add_sequence(Seq("seq1", "CCCAAAGGG", 0, &nuc_encoding_scheme));
    // mseq.add_sequence(Seq("seq2", "GGGAAUACCC", 0, &nuc_encoding_scheme));

    // mseq.add_sequence(Seq("seq1",
    // "ccgggugccuauaccggaggggccacacccguucccauuccgaacacggucguuaagcccuccagggccgaugguacuggggcguuaccgcccugggagaguaggucggugcccggg",
    // 0, &nuc_encoding_scheme)); mseq.add_sequence(Seq("seq1",
    // "ugcuuggcgaccauagcguuauggacccaccugaucccaugccgaacucaguagugaaacguaauagcgccgaugguaguguggggucuccccaugugagaguaggacaucgccaggcau",
    // 0, &nuc_encoding_scheme)); mseq.add_sequence(Seq("seq2",
    // "ccgggugccuauaccggaggggccacacccguucccauuccgaacacggucguuaagcccuccagggccgaugguacuggggcguuaccgcccugggagaguaggucggugcccggg",
    // 1, &nuc_encoding_scheme)); mseq.add_sequence(Seq("seq3",
    // "ccgggugccuauaccggaggggccacacccguucccauuccgaacacggucguuaagcccuccagggccgaugguacuggggcguuaccgcccugggagaguaggucggugccggg",
    // 2, &nuc_encoding_scheme));

    // mseq.add_sequence(
    //     Seq("seq1",
    //         "acaugcaagucgagcgccccgcaaggggagcggcagacgggugaguaacgcgugggaaucuacccaucucuacggaacaacuccgggaaacuggagcuaauaccgu"
    //         "auacguccuucgggagaaagauuuaucggagauggaugagcccgcguuggauuagcuaguuggugggguaauggccuaccaaggcgacgauccauagcuggucuga"
    //         "gaggaugaucagccacacugggacugagacacggcccagacuccuacgggaggcagcaguggggaauauuggacaaugggcgcaagccugauccagccaugccgcg"
    //         "ugagugaugaaggcccuaggguuguaaagcucuuucaacggugaagauaaugacgguaaccguagaagaagccccggcuaacuucgugccagcagccgcgguaaua"
    //         "cgaagggggcuagcguuguucggaauuacugggcguaaagcgcacguaggcggauauuuaagucaggggugaaaucccggggcucaaccccggaacugccuuugau"
    //         "acuggguaucucgaguccggaagaggugaguggaauuccgaguguagaggugaaauucguagauauucggaggaacaccaguggcgaaggcggcucacugguccgg"
    //         "uacugacgcugaggugcgaaagcguggggagcaaacaggauuagauacccugguaguccacgccguaaacgauggaagcuagccguuggcaaguuuacuugucggu"
    //         "ggcgcagcuaacgcauuaagcuucccgccuggggaguacggucgcaagauuaaaacucaaaggaauugacgggggcccgcacaagcgguggagcaugugguuuaau"
    //         "ucgaagcaacgcgcagaaccuuaccagcccuugacaucccggucgcgguuuccagagauggaaaccuucaguucggcuggaccggugacaggugcugcauggcugu"
    //         "cgucagcucgugucgugagauguuggguuaagucccgcaacgagcgcaacccucgcccuuaguugccagcauucaguugggcacucuaaggggacugccggugaua"
    //         "agccgagaggaagguggggaugacgucaaguccucauggcccuuacgggcugggcuacacacgugcuacaaugguggugacagugggcagcgagaccgcgaggucg"
    //         "agcuaaucuccaaaagccaucucaguucggauugcacucugcaacucgagugcaugaaguuggaaucgcuaguaaucgcggaucagcaugccgcggugaauacguu"
    //         "cccgggccuuguacacaccgcccgucacaccaugggaguugguuuuacccgaaggcgcugugcuaaccgcaa",
    //         0, &nuc_encoding_scheme));
    // mseq.add_sequence(Seq(
    //     "seq2",
    //     "gcgaacgcuggcggcaggcuuaacacaugcaagucgagcgggcauagcaauaugucagcggcagacgggugaguaacgcgugggaacguaccuuuugguucggaacaaca"
    //     "cagggaaacuugugcuaauaccggauaagcccuuacggggaaagauuuaucgccgaaagaucggcccgcgucugauuagcuaguuggugagguaauggcucaccaaggcg"
    //     "acgaucaguagcuggucugagaggaugaucagccacauugggacugagacacggcccaaacuccuacgggaggcagcaguggggaauauuggacaaugggcgcaagccug"
    //     "auccagccaugccgcgugagugaugaaggcccuaggguuguaaagcucuuuugugcgggaagauaaugacgguaccgcaagaauaagccccggcuaacuucgugccagca"
    //     "gccgcgguaauacgaagggggcuagcguugcucggaaucacugggcguaaagggugcguaggcgggucuuuaagucaggggugaaauccuggagcucaacuccagaacug"
    //     "ccuuugauacugaagaucuugaguucgggagaggugaguggaacugcgaguguagaggugaaauucguagauauucgcaagaacaccaguggcgaaggcggcucacuggc"
    //     "ccgauacugacgcugaggcacgaaagcguggggagcaaacaggauuagauacccugguaguccacgccguaaacgaugaaugccagccguuaguggguuuacucacuagu"
    //     "ggcgcagcuaacgcuuuaagcauuccgccuggggaguacggucgcaagauuaaaacucaaaggaauugacgggggcccgcacaagcgguggagcaugugguuuaauucga"
    //     "cgcaacgcgcagaaccuuaccagcccuugacaucccggucgcggacuccagagacggaguucuucaguucggcuggaccggagacaggugcugcauggcugucgucagcu"
    //     "cgugucgugagauguuggguuaagucccgcaacgagcgcaacccccguccuuaguugcuaccauuuaguugagcacucuaaggagacugccggugauaagccgcgaggaa"
    //     "gguggggaugacgucaaguccucauggcccuuacgggcugggcuacacacgugcuacaauggcggugacaaugggaugcuaaggggcgacccuucgcaaaucucaaaaag"
    //     "ccgucucaguucggauugggcucugcaacucgagcccaugaaguuggaaucgcuaguaaucguggaucagcacgccacggugaauacguucccgggccuuguacacaccg"
    //     "cccgucacaccaugggaguugguuuuaccugaagacggugcgcuaacccgcaagggaggcagccggccacgguagggucagcgacuggggug",
    //     0, &nuc_encoding_scheme));

    // LinearTurboFold ltf(&mseq, 1, VerboseState::DEBUG);
    // ltf.run();

    // return 0;
}
