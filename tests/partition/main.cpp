#include "./../../partition/partition.hpp"
#include <iostream>

using namespace std;

int main() {
    
    Seq seq1("seq1","AUUAAAGGUUUAUACCUUCCCAGGUAACAAACCAACCAACUUUCGAUCUCUUGUAGAUCUGUUCUCUAAACGAACUUUAAAAUCUGUGUGGCUGUCACUCGGCUGCAUGCUUAGUGCACUCACGCAGUAUAAUUAAUAACUAAUUACUGUCGUUGACAGGACACGAGUAACUCGUCUAUCUUCUGCAGGCUGCUUACGGUUUCGUCCGUGUUGCAGCCGAUCAUCAGCACAUCUAGGUUUCGUCCGGGUGUGACCGAAAGGUAAGAUGGAGAGCCUUGUCCCUGGUUUCAACGAGAAAACACACGUCCAACUCAGUUUGCCUGUUUUACAGGUUCGCGACGUGCUCGUACGUGGCUUUGGAGACUCCGUGGAGGAGGUCUUAUCAGAGGCACGUCAACAUCUUAAAGAUGGCACUUGUGGCUUAGUAGAAGUUGAAAAAGGCGUUUUGCCUCAACUUGAACAGCCCUAUGUGUUCAUCAAACGUUCGGAUGCUCGAACUGCACCUCAUGGUCAUGUUAUGGUUGAGCUGGUAGCAGAACUCGAAGGCAUUCAGUACGGUCGUAGUGGUGAGACACUUGGUGUCCUUGUCCCUCAUGUGGGCGAAAUACCAGUGGCUUACCGCAAGGUUCUUCUUCGUAAGAACGGUAAUAAAGGAGCUGGUGGCCAUAGUUACGGCGCCGAUCUAAAGUCAUUUGACUUAGGCGACGAGCUUGGCACUGAUCCUUAUGAAGAUUUUCAAGAAAACUGGAACACUAAACAUAGCAGUGGUGUUACCCGUGAACUCAUGCGUGAGCUUAACGGAGGGGCAUACACUCGCUAUGUCGAUAACAACUUCUGUGGCCCUGAUGGCUACCCUCUUGAGUGCAUUAAAGACCUUCUAGCACGUGCUGGUAAAGCUUCAUGCACUUUGUCCGAACAACUGGACUUUAUUGACACUAAGAGGGGUGUAUACUGCUGCCGUGAACAUGAGCAUGAAAUUGCUUGGUACACGGAACGUUCUGAAAAGAGCUAUGAAUUGCAGACACCUUUUGAAAUUAAAUUGGCAAAGAAAUUUGACACCUUCAAUGGGGAAUGUCCAAAUUUUGUAUUUCCCUUAAAUUCCAUAAUCAAGACUAUUCAACCAAGGGUUGAAAAGAAAAAGCUUGAUGGCUUUAUGGGUAGAAUUCGAUCUGUCUAUCCAGUUGCGUCACCAAAUGAAUGCAACCAAAUGUGCCUUUCAACUCUCAUGAAGUGUGAUCAUUGUGGUGAAACUUCAUGGCAGACGGGCGAUUUUGUUAAAGCCACUUGCGAAUUUUGUGGCACUGAGAAUUUGACUAAAGAAGGUGCCACUACUUGUGGUUACUUACCCCAAAAUGCUGUUGUUAAAAUUUAUUGUCCAGCAUGUCACAAUUCAGAAGUAGGACCUGAGCAUAGUCUUGCCGAAUACCAUAAUGAAUCUGGCUUGAAAACCAUUCUUCGUAAGGGUGGUCGCACUAUUGCCUUUGGAGGCUGUGUGUUCUCUUAUGUUGGUUGCCAUAACAAGUGUGCCUAUUGGGUUCCACGUGCUAGCGCUAACAUAGGUUGUAACCAUACAGGUGUUGUUGGAGAAGGUUCCGAAGGUCUUAAUGACAACCUUCUUGAAAUACUCCAAAAAGAGAAAGUCAACAUCAAUAUUGUUGGUGACUUUAAACUUAAUGAAGAGAUCGCCAUUAUUUUGGCAUCUUUUUCUGCUUCCACAAGUGCUUUUGUGGAAACUGUGAAAGGUUUGGAUUAUAAAGCAUUCAAACAAAUUGUUGAAUCCUGUGGUAAUUUUAAAGUUACAAAAGGAAAAGCUAAAAAAGGUGCCUGGAAUAUUGGUGAACAGAAAUCAAUACUGAGUCCUCUUUAUGCAUUUGCAUCAGAGGCUGCUCGUGUUGUACGAUCAAUUUUCUCCCGCACUCUUGAAACUGCUCAAAAUUCUGUGCGUGUUUUACAGAAGGCCGCUAUAACAAUACUAGAUGGAAUUUCACAGUAUUCACUGAGACUCAUUGAUGCUAUGAUGUUCACAUCUGAUUUGGCUACUAACAAUCUAGUUGUAAUGGCCUACAUUACAGGUGGUGUUGUUCAGUUGACUUCGCAGUGGCUAACUAACAUCUUUGGCACUGUUUAUGAAAAACUCAAACCCGUCCUUGAUUGGCUUGAAGAGAAGUUUAAGGAAGGUGUAGAGUUUCUUAGAGACGGUUGGGAAAUUGUUAAAUUUAUCUCAACCUGUGCUUGUGAAAUUGUCGGUGGACAAAUUGUCACCUGUGCAAAGGAAAUUAAGGAGAGUGUUCAGACAUUCUUUAAGCUUGUAAAUAAAUUUUUGGCUUUGUGUGCUGACUCUAUCAUUAUUGGUGGAGCUAAACUUAAAGCCUUGAAUUUAGGUGAAACAUUUGUCACGCACUCAAAGGGAUUGUACAGAAAGUGUGUUAAAUCCAGAGAAGAAACUGGCCUACUCAUGCCUCUAAAAGCCCCAAAAGAAAUUAUCUUCUUAGAGGGAGAAACACUUCCCACAGAAGUGUUAACAGAGGAAGUUGUCUUGAAAACUGGUGAUUUACAACCAUUAGAACAACCUACUAGUGAAGCUGUUGAAGCUCCAUUGGUUGGUACACCAGUUUGUAUUAACGGGCUUAUGUUGCUCGAAAUCAAAGACACAGAAAAGUACUGUGCCCUUGCACCUAAUAUGAUGGUAACAAACAAUACCUUCACACUCAAAGGCGGUGCACCAACAAAGGUUACUUUUGGUGAUGACACUGUGAUAGAAGUGCAAGGUUACAAGAGUGUGAAUAUCACUUUUGAACUUGAUGAAAGGAUUGAUAAAGUACUUAAUGAGAAGUGCUCUGCCUAUACAGUUGAACUCGGUACAGAAGUAAAUGAGUUCGCCUGUGUUGUGGCAGAUGCUGUCAUAAAAACUUUGCAACCAGUAUCUGAAUUACUUACACCACUGGGCAUUGAUUUAGAUGAGUGGAGUAUGGCUACAUACUACUUAUUUGAUGAGUCUGGUGAGUUUAAAUUGGCUUCACAUAUGUAUUGUUCUUUCUACCCUCCAGAUGAGGAUGAAGAAGAAGGUGAUUGUGAAGAAGAAGAGUUUGAGCCAUCAACUCAAUAUGAGUAUGGUACUGAAGAUGAUUACCAAGGUAAACCUUUGGAAUUUGGUGCCACUUCUGCUGCUCUUCAACCUGAAGAAGAGCAAGAAGAAGAUUGGUUAGAUGAUGAUAGUCAACAAACUGUUGGUCAACAAGACGGCAGUGAGGACAAUCAGACAACUACUAUUCAAACAAUUGUUGAGGUUCAACCUCAAUUAGAGAUGGAACUUACACCAGUUGUUCAGACUAUUGAAGUGAAUAGUUUUAGUGGUUAUUUAAAACUUACUGACAAUGUAUACAUUAAAAAUGCAGACAUUGUGGAAGAAGCUAAAAAGGUAAAACCAACAGUGGUUGUUAAUGCAGCCAAUGUUUACCUUAAACAUGGAGGAGGUGUUGCAGGAGCCUUAAAUAAGGCUACUAACAAUGCCAUGCAAGUUGAAUCUGAUGAUUACAUAGCUACUAAUGGACCACUUAAAGUGGGUGGUAGUUGUGUUUUAAGCGGACACAAUCUUGCUAAACACUGUCUUCAUGUUGUCGGCCCAAAUGUUAACAAAGGUGAAGACAUUCAACUUCUUAAGAGUGCUUAUGAAAAUUUUAAUCAGCACGAAGUUCUACUUGCACCAUUAUUAUCAGCUGGUAUUUUUGGUGCUGACCCUAUACAUUCUUUAAGAGUUUGUGUAGAUACUGUUCGCACAAAUGUCUACUUAGCUGUCUUUGAUAAAAAUCUCUAUGACAAACUUGUUUCAAGCUUUUUGGAAAUGAAGAGUGAAAAGCAAGUUGAACAAAAGAUCGCUGAGAUUCCUAAAGAGGAAGUUAAGCCAUUUAUAACUGAAAGUAAACCUUCAGUUGAACAGAGAAAACAAGAUGAUAAGAAAAUCAAAGCUUGUGUUGAAGAAGUUACAACAACUCUGGAAGAAACUAAGUUCCUCACAGAAAACUUGUUACUUUAUAUUGACAUUAAUGGCAAUCUUCAUCCAGAUUCUGCCACUCUUGUUAGUGACAUUGACAUCACUUUCUUAAAGAAAGAUGCUCCAUAUAUAGUGGGUGAUGUUGUUCAAGAGGGUGUUUUAACUGCUGUGGUUAUACCUACUAAAAAGGCUGGUGGCACUACUGAAAUGCUAGCGAAAGCUUUGAGAAAAGUGCCAACAGACAAUUAUAUAACCACUUACCCGGGUCAGGGUUUAAAUGGUUACACUGUAGAGGAGGCAAAGACAGUGCUUAAAAAGUGUAAAAGUGCCUUUUACAUUCUACCAUCUAUUAUCUCUAAUGAGAAGCAAGAAAUUCUUGGAACUGUUUCUUGGAAUUUGCGAGAAAUGCUUGCACAUGCAGAAGAAACACGCAAAUUAAUGCCUGUCUGUGUGGAAACUAAAGCCAUAGUUUCAACUAUACAGCGUAAAUAUAAGGGUAUUAAAAUACAAGAGGGUGUGGUUGAUUAUGGUGCUAGAUUUUACUUUUACACCAGUAAAACAACUGUAGCGUCACUUAUCAACACACUUAACGAUCUAAAUGAAACUCUUGUUACAAUGCCACUUGGCUAUGUAACACAUGGCUUAAAUUUGGAAGAAGCUGCUCGGUAUAUGAGAUCUCUCAAAGUGCCAGCUACAGUUUCUGUUUCUUCACCUGAUGCUGUUACAGCGUAUAAUGGUUAUCUUACUUCUUCUUCUAAAACACCUGAAGAACAUUUUAUUGAAACCAUCUCACUUGCUGGUUCCUAUAAAGAUUGGUCCUAUUCUGGACAAUCUACACAACUAGGUAUAGAAUUUCUUAAGAGAGGUGAUAAAAGUGUAUAUUACACUAGUAAUCCUACCACAUUCCACCUAGAUGGUGAAGUUAUCACCUUUGACAAUCUUAAGACACUUCUUUCUUUGAGAGAAGUGAGGACUAUUAAGGUGUUUACAACAGUAGACAACAUUAACCUCCACACGCAAGUUGUGGACAUGUCAAUGACAUAUGGACAACAGUUUGGUCCAACUUAUUUGGAUGGAGCUGAUGUUACUAAAAUAAAACCUCAUAAUUCACAUGAAGGUAAAACAUUUUAUGUUUUACCUAAUGAUGACACUCUACGUGUUGAGGCUUUUGAGUACUACCACACAACUGAUCCUAGUUUUCUGGGUAGGUACAUGUCAGCAUUAAAUCACACUAAAAAGUGGAAAUACCCACAAGUUAAUGGUUUAACUUCUAUUAAAUGGGCAGAUAACAACUGUUAUCUUGCCACUGCAUUGUUAACACUCCAACAAAUAGAGUUGAAGUUUAAUCCACCUGCUCUACAAGAUGCUUAUUACAGAGCAAGGGCUGGUGAAGCUGCUAACUUUUGUGCACUUAUCUUAGCCUACUGUAAUAAGACAGUAGGUGAGUUAGGUGAUGUUAGAGAAACAAUGAGUUACUUGUUUCAACAUGCCAAUUUAGAUUCUUGCAAAAGAGUCUUGAACGUGGUGUGUAAAACUUGUGGACAACAGCAGACAACCCUUAAGGGUGUAGAAGCUGUUAUGUACAUGGGCACACUUUCUUAUGAACAAUUUAAGAAAGGUGUUCAGAUACCUUGUACGUGUGGUAAACAAGCUACAAAAUAUCUAGUACAACAGGAGUCACCUUUUGUUAUGAUGUCAGCACCACCUGCUCAGUAUGAACUUAAGCAUGGUACAUUUACUUGUGCUAGUGAGUACACUGGUAAUUACCAGUGUGGUCACUAUAAACAUAUAACUUCUAAAGAAACUUUGUAUUGCAUAGACGGUGCUUUACUUACAAAGUCCUCAGAAUACAAAGGUCCUAUUACGGAUGUUUUCUACAAAGAAAACAGUUACACAACAACCAUAAAACCAGUUACUUAUAAAUUGGAUGGUGUUGUUUGUACAGAAAUUGACCCUAAGUUGGACAAUUAUUAUAAGAAAGACAAUUCUUAUUUCACAGAGCAACCAAUUGAUCUUGUACCAAACCAACCAUAUCCAAACGCAAGCUUCGAUAAUUUUAAGUUUGUAUGUGAUAAUAUCAAAUUUGCUGAUGAUUUAAACCAGUUAACUGGUUAUAAGAAACCUGCUUCAAGAGAGCUUAAAGUUACAUUUUUCCCUGACUUAAAUGGUGAUGUGGUGGCUAUUGAUUAUAAACACUACACACCCUCUUUUAAGAAAGGAGCUAAAUUGUUACAUAAACCUAUUGUUUGGCAUGUUAACAAUGCAACUAAUAAAGCCACGUAUAAACCAAAUACCUGGUGUAUACGUUGUCUUUGGAGCACAAAACCAGUUGAAACAUCAAAUUCGUUUGAUGUACUGAAGUCAGAGGACGCGCAGGGAAUGGAUAAUCUUGCCUGCGAAGAUCUAAAACCAGUCUCUGAAGAAGUAGUGGAAAAUCCUACCAUACAGAAAGACGUUCUUGAGUGUAAUGUGAAAACUACCGAAGUUGUAGGAGACAUUAUACUUAAACCAGCAAAUAAUAGUUUAAAAAUUACAGAAGAGGUUGGCCACACAGAUCUAAUGGCUGCUUAUGUAGACAAUUCUAGUCUUACUAUUAAGAAACCUAAUGAAUUAUCUAGAGUAUUAGGUUUGAAAACCCUUGCUACUCAUGGUUUAGCUGCUGUUAAUAGUGUCCCUUGGGAUACUAUAGCUAAUUAUGCUAAGCCUUUUCUUAACAAAGUUGUUAGUACAACUACUAACAUAGUUACACGGUGUUUAAACCGUGUUUGUACUAAUUAUAUGCCUUAUUUCUUUACUUUAUUGCUACAAUUGUGUACUUUUACUAGAAGUACAAAUUCUAGAAUUAAAGCAUCUAUGCCGACUACUAUAGCAAAGAAUACUGUUAAGAGUGUCGGUAAAUUUUGUCUAGAGGCUUCAUUUAAUUAUUUGAAGUCACCUAAUUUUUCUAAACUGAUAAAUAUUAUAAUUUGGUUUUUACUAUUAAGUGUUUGCCUAGGUUCUUUAAUCUACUCAACCGCUGCUUUAGGUGUUUUAAUGUCUAAUUUAGGCAUGCCUUCUUACUGUACUGGUUACAGAGAAGGCUAUUUGAACUCUACUAAUGUCACUAUUGCAACCUACUGUACUGGUUCUAUACCUUGUAGUGUUUGUCUUAGUGGUUUAGAUUCUUUAGACACCUAUCCUUCUUUAGAAACUAUACAAAUUACCAUUUCAUCUUUUAAAUGGGAUUUAACUGCUUUUGGCUUAGUUGCAGAGUGGUUUUUGGCAUAUAUUCUUUUCACUAGGUUUUUCUAUGUACUUGGAUUGGCUGCAAUCAUGCAAUUGUUUUUCAGCUAUUUUGCAGUACAUUUUAUUAGUAAUUCUUGGCUUAUGUGGUUAAUAAUUAAUCUUGUACAAAUGGCCCCGAUUUCAGCUAUGGUUAGAAUGUACAUCUUCUUUGCAUCAUUUUAUUAUGUAUGGAAAAGUUAUGUGCAUGUUGUAGACGGUUGUAAUUCAUCAACUUGUAUGAUGUGUUACAAACGUAAUAGAGCAACAAGAGUCGAAUGUACAACUAUUGUUAAUGGUGUUAGAAGGUCCUUUUAUGUCUAUGCUAAUGGAGGUAAAGGCUUUUGCAAACUACACAAUUGGAAUUGUGUUAAUUGUGAUACAUUCUGUGCUGGUAGUACAUUUAUUAGUGAUGAAGUUGCGAGAGACUUGUCACUACAGUUUAAAAGACCAAUAAAUCCUACUGACCAGUCUUCUUACAUCGUUGAUAGUGUUACAGUGAAGAAUGGUUCCAUCCAUCUUUACUUUGAUAAAGCUGGUCAAAAGACUUAUGAAAGACAUUCUCUCUCUCAUUUUGUUAACUUAGACAACCUGAGAGCUAAUAACACUAAAGGUUCAUUGCCUAUUAAUGUUAUAGUUUUUGAUGGUAAAUCAAAAUGUGAAGAAUCAUCUGCAAAAUCAGCGUCUGUUUACUACAGUCAGCUUAUGUGUCAACCUAUACUGUUACUAGAUCAGGCAUUAGUGUCUGAUGUUGGUGAUAGUGCGGAAGUUGCAGUUAAAAUGUUUGAUGCUUACGUUAAUACGUUUUCAUCAACUUUUAACGUACCAAUGGAAAAACUCAAAACACUAGUUGCAACUGCAGAAGCUGAACUUGCAAAGAAUGUGUCCUUAGACAAUGUCUUAUCUACUUUUAUUUCAGCAGCUCGGCAAGGGUUUGUUGAUUCAGAUGUAGAAACUAAAGAUGUUGUUGAAUGUCUUAAAUUGUCACAUCAAUCUGACAUAGAAGUUACUGGCGAUAGUUGUAAUAACUAUAUGCUCACCUAUAACAAAGUUGAAAACAUGACACCCCGUGACCUUGGUGCUUGUAUUGACUGUAGUGCGCGUCAUAUUAAUGCGCAGGUAGCAAAAAGUCACAACAUUGCUUUGAUAUGGAACGUUAAAGAUUUCAUGUCAUUGUCUGAACAACUACGAAAACAAAUACGUAGUGCUGCUAAAAAGAAUAACUUACCUUUUAAGUUGACAUGUGCAACUACUAGACAAGUUGUUAAUGUUGUAACAACAAAGAUAGCACUUAAGGGUGGUAAAAUUGUUAAUAAUUGGUUGAAGCAGUUAAUUAAAGUUACACUUGUGUUCCUUUUUGUUGCUGCUAUUUUCUAUUUAAUAACACCUGUUCAUGUCAUGUCUAAACAUACUGACUUUUCAAGUGAAAUCAUAGGAUACAAGGCUAUUGAUGGUGGUGUCACUCGUGACAUAGCAUCUACAGAUACUUGUUUUGCUAACAAACAUGCUGAUUUUGACACAUGGUUUAGCCAGCGUGGUGGUAGUUAUACUAAUGACAAAGCUUGCCCAUUGAUUGCUGCAGUCAUAACAAGAGAAGUGGGUUUUGUCGUGCCUGGUUUGCCUGGCACGAUAUUACGCACAACUAAUGGUGACUUUUUGCAUUUCUUACCUAGAGUUUUUAGUGCAGUUGGUAACAUCUGUUACACACCAUCAAAACUUAUAGAGUACACUGACUUUGCAACAUCAGCUUGUGUUUUGGCUGCUGAAUGUACAAUUUUUAAAGAUGCUUCUGGUAAGCCAGUACCAUAUUGUUAUGAUACCAAUGUACUAGAAGGUUCUGUUGCUUAUGAAAGUUUACGCCCUGACACACGUUAUGUGCUCAUGGAUGGCUCUAUUAUUCAAUUUCCUAACACCUACCUUGAAGGUUCUGUUAGAGUGGUAACAACUUUUGAUUCUGAGUACUGUAGGCACGGCACUUGUGAAAGAUCAGAAGCUGGUGUUUGUGUAUCUACUAGUGGUAGAUGGGUACUUAACAAUGAUUAUUACAGAUCUUUACCAGGAGUUUUCUGUGGUGUAGAUGCUGUAAAUUUACUUACUAAUAUGUUUACACCACUAAUUCAACCUAUUGGUGCUUUGGACAUAUCAGCAUCUAUAGUAGCUGGUGGUAUUGUAGCUAUCGUAGUAACAUGCCUUGCCUACUAUUUUAUGAGGUUUAGAAGAGCUUUUGGUGAAUACAGUCAUGUAGUUGCCUUUAAUACUUUACUAUUCCUUAUGUCAUUCACUGUACUCUGUUUAACACCAGUUUACUCAUUCUUACCUGGUGUUUAUUCUGUUAUUUACUUGUACUUGACAUUUUAUCUUACUAAUGAUGUUUCUUUUUUAGCACAUAUUCAGUGGAUGGUUAUGUUCACACCUUUAGUACCUUUCUGGAUAACAAUUGCUUAUAUCAUUUGUAUUUCCACAAAGCAUUUCUAUUGGUUCUUUAGUAAUUACCUAAAGAGACGUGUAGUCUUUAAUGGUGUUUCCUUUAGUACUUUUGAAGAAGCUGCGCUGUGCACCUUUUUGUUAAAUAAAGAAAUGUAUCUAAAGUUGCGUAGUGAUGUGCUAUUACCUCUUACGCAAUAUAAUAGAUACUUAGCUCUUUAUAAUAAGUACAAGUAUUUUAGUGGAGCAAUGGAUACAACUAGCUACAGAGAAGCUGCUUGUUGUCAUCUCGCAAAGGCUCUCAAUGACUUCAGUAACUCAGGUUCUGAUGUUCUUUACCAACCACCACAAACCUCUAUCACCUCAGCUGUUUUGCAGAGUGGUUUUAGAAAAAUGGCAUUCCCAUCUGGUAAAGUUGAGGGUUGUAUGGUACAAGUAACUUGUGGUACAACUACACUUAACGGUCUUUGGCUUGAUGACGUAGUUUACUGUCCAAGACAUGUGAUCUGCACCUCUGAAGACAUGCUUAACCCUAAUUAUGAAGAUUUACUCAUUCGUAAGUCUAAUCAUAAUUUCUUGGUACAGGCUGGUAAUGUUCAACUCAGGGUUAUUGGACAUUCUAUGCAAAAUUGUGUACUUAAGCUUAAGGUUGAUACAGCCAAUCCUAAGACACCUAAGUAUAAGUUUGUUCGCAUUCAACCAGGACAGACUUUUUCAGUGUUAGCUUGUUACAAUGGUUCACCAUCUGGUGUUUACCAAUGUGCUAUGAGGCCCAAUUUCACUAUUAAGGGUUCAUUCCUUAAUGGUUCAUGUGGUAGUGUUGGUUUUAACAUAGAUUAUGACUGUGUCUCUUUUUGUUACAUGCACCAUAUGGAAUUACCAACUGGAGUUCAUGCUGGCACAGACUUAGAAGGUAACUUUUAUGGACCUUUUGUUGACAGGCAAACAGCACAAGCAGCUGGUACGGACACAACUAUUACAGUUAAUGUUUUAGCUUGGUUGUACGCUGCUGUUAUAAAUGGAGACAGGUGGUUUCUCAAUCGAUUUACCACAACUCUUAAUGACUUUAACCUUGUGGCUAUGAAGUACAAUUAUGAACCUCUAACACAAGACCAUGUUGACAUACUAGGACCUCUUUCUGCUCAAACUGGAAUUGCCGUUUUAGAUAUGUGUGCUUCAUUAAAAGAAUUACUGCAAAAUGGUAUGAAUGGACGUACCAUAUUGGGUAGUGCUUUAUUAGAAGAUGAAUUUACACCUUUUGAUGUUGUUAGACAAUGCUCAGGUGUUACUUUCCAAAGUGCAGUGAAAAGAACAAUCAAGGGUACACACCACUGGUUGUUACUCACAAUUUUGACUUCACUUUUAGUUUUAGUCCAGAGUACUCAAUGGUCUUUGUUCUUUUUUUUGUAUGAAAAUGCCUUUUUACCUUUUGCUAUGGGUAUUAUUGCUAUGUCUGCUUUUGCAAUGAUGUUUGUCAAACAUAAGCAUGCAUUUCUCUGUUUGUUUUUGUUACCUUCUCUUGCCACUGUAGCUUAUUUUAAUAUGGUCUAUAUGCCUGCUAGUUGGGUGAUGCGUAUUAUGACAUGGUUGGAUAUGGUUGAUACUAGUUUGUCUGGUUUUAAGCUAAAAGACUGUGUUAUGUAUGCAUCAGCUGUAGUGUUACUAAUCCUUAUGACAGCAAGAACUGUGUAUGAUGAUGGUGCUAGGAGAGUGUGGACACUUAUGAAUGUCUUGACACUCGUUUAUAAAGUUUAUUAUGGUAAUGCUUUAGAUCAAGCCAUUUCCAUGUGGGCUCUUAUAAUCUCUGUUACUUCUAACUACUCAGGUGUAGUUACAACUGUCAUGUUUUUGGCCAGAGGUAUUGUUUUUAUGUGUGUUGAGUAUUGCCCUAUUUUCUUCAUAACUGGUAAUACACUUCAGUGUAUAAUGCUAGUUUAUUGUUUCUUAGGCUAUUUUUGUACUUGUUACUUUGGCCUCUUUUGUUUACUCAACCGCUACUUUAGACUGACUCUUGGUGUUUAUGAUUACUUAGUUUCUACACAGGAGUUUAGAUAUAUGAAUUCACAGGGACUACUCCCACCCAAGAAUAGCAUAGAUGCCUUCAAACUCAACAUUAAAUUGUUGGGUGUUGGUGGCAAACCUUGUAUCAAAGUAGCCACUGUACAGUCUAAAAUGUCAGAUGUAAAGUGCACAUCAGUAGUCUUACUCUCAGUUUUGCAACAACUCAGAGUAGAAUCAUCAUCUAAAUUGUGGGCUCAAUGUGUCCAGUUACACAAUGACAUUCUCUUAGCUAAAGAUACUACUGAAGCCUUUGAAAAAAUGGUUUCACUACUUUCUGUUUUGCUUUCCAUGCAGGGUGCUGUAGACAUAAACAAGCUUUGUGAAGAAAUGCUGGACAACAGGGCAACCUUACAAGCUAUAGCCUCAGAGUUUAGUUCCCUUCCAUCAUAUGCAGCUUUUGCUACUGCUCAAGAAGCUUAUGAGCAGGCUGUUGCUAAUGGUGAUUCUGAAGUUGUUCUUAAAAAGUUGAAGAAGUCUUUGAAUGUGGCUAAAUCUGAAUUUGACCGUGAUGCAGCCAUGCAACGUAAGUUGGAAAAGAUGGCUGAUCAAGCUAUGACCCAAAUGUAUAAACAGGCUAGAUCUGAGGACAAGAGGGCAAAAGUUACUAGUGCUAUGCAGACAAUGCUUUUCACUAUGCUUAGAAAGUUGGAUAAUGAUGCACUCAACAACAUUAUCAACAAUGCAAGAGAUGGUUGUGUUCCCUUGAACAUAAUACCUCUUACAACAGCAGCCAAACUAAUGGUUGUCAUACCAGACUAUAACACAUAUAAAAAUACGUGUGAUGGUACAACAUUUACUUAUGCAUCAGCAUUGUGGGAAAUCCAACAGGUUGUAGAUGCAGAUAGUAAAAUUGUUCAACUUAGUGAAAUUAGUAUGGACAAUUCACCUAAUUUAGCAUGGCCUCUUAUUGUAACAGCUUUAAGGGCCAAUUCUGCUGUCAAAUUACAGAAUAAUGAGCUUAGUCCUGUUGCACUACGACAGAUGUCUUGUGCUGCCGGUACUACACAAACUGCUUGCACUGAUGACAAUGCGUUAGCUUACUACAACACAACAAAGGGAGGUAGGUUUGUACUUGCACUGUUAUCCGAUUUACAGGAUUUGAAAUGGGCUAGAUUCCCUAAGAGUGAUGGAACUGGUACUAUCUAUACAGAACUGGAACCACCUUGUAGGUUUGUUACAGACACACCUAAAGGUCCUAAAGUGAAGUAUUUAUACUUUAUUAAAGGAUUAAACAACCUAAAUAGAGGUAUGGUACUUGGUAGUUUAGCUGCCACAGUACGUCUACAAGCUGGUAAUGCAACAGAAGUGCCUGCCAAUUCAACUGUAUUAUCUUUCUGUGCUUUUGCUGUAGAUGCUGCUAAAGCUUACAAAGAUUAUCUAGCUAGUGGGGGACAACCAAUCACUAAUUGUGUUAAGAUGUUGUGUACACACACUGGUACUGGUCAGGCAAUAACAGUUACACCGGAAGCCAAUAUGGAUCAAGAAUCCUUUGGUGGUGCAUCGUGUUGUCUGUACUGCCGUUGCCACAUAGAUCAUCCAAAUCCUAAAGGAUUUUGUGACUUAAAAGGUAAGUAUGUACAAAUACCUACAACUUGUGCUAAUGACCCUGUGGGUUUUACACUUAAAAACACAGUCUGUACCGUCUGCGGUAUGUGGAAAGGUUAUGGCUGUAGUUGUGAUCAACUCCGCGAACCCAUGCUUCAGUCAGCUGAUGCACAAUCGUUUUUAAACGGGUUUGCGGUGUAAGUGCAGCCCGUCUUACACCGUGCGGCACAGGCACUAGUACUGAUGUCGUAUACAGGGCUUUUGACAUCUACAAUGAUAAAGUAGCUGGUUUUGCUAAAUUCCUAAAAACUAAUUGUUGUCGCUUCCAAGAAAAGGACGAAGAUGACAAUUUAAUUGAUUCUUACUUUGUAGUUAAGAGACACACUUUCUCUAACUACCAACAUGAAGAAACAAUUUAUAAUUUACUUAAGGAUUGUCCAGCUGUUGCUAAACAUGACUUCUUUAAGUUUAGAAUAGACGGUGACAUGGUACCACAUAUAUCACGUCAACGUCUUACUAAAUACACAAUGGCAGACCUCGUCUAUGCUUUAAGGCAUUUUGAUGAAGGUAAUUGUGACACAUUAAAAGAAAUACUUGUCACAUACAAUUGUUGUGAUGAUGAUUAUUUCAAUAAAAAGGACUGGUAUGAUUUUGUAGAAAACCCAGAUAUAUUACGCGUAUACGCCAACUUAGGUGAACGUGUACGCCAAGCUUUGUUAAAAACAGUACAAUUCUGUGAUGCCAUGCGAAAUGCUGGUAUUGUUGGUGUACUGACAUUAGAUAAUCAAGAUCUCAAUGGUAACUGGUAUGAUUUCGGUGAUUUCAUACAAACCACGCCAGGUAGUGGAGUUCCUGUUGUAGAUUCUUAUUAUUCAUUGUUAAUGCCUAUAUUAACCUUGACCAGGGCUUUAACUGCAGAGUCACAUGUUGACACUGACUUAACAAAGCCUUACAUUAAGUGGGAUUUGUUAAAAUAUGACUUCACGGAAGAGAGGUUAAAACUCUUUGACCGUUAUUUUAAAUAUUGGGAUCAGACAUACCACCCAAAUUGUGUUAACUGUUUGGAUGACAGAUGCAUUCUGCAUUGUGCAAACUUUAAUGUUUUAUUCUCUACAGUGUUCCCACCUACAAGUUUUGGACCACUAGUGAGAAAAAUAUUUGUUGAUGGUGUUCCAUUUGUAGUUUCAACUGGAUACCACUUCAGAGAGCUAGGUGUUGUACAUAAUCAGGAUGUAAACUUACAUAGCUCUAGACUUAGUUUUAAGGAAUUACUUGUGUAUGCUGCUGACCCUGCUAUGCACGCUGCUUCUGGUAAUCUAUUACUAGAUAAACGCACUACGUGCUUUUCAGUAGCUGCACUUACUAACAAUGUUGCUUUUCAAACUGUCAAACCCGGUAAUUUUAACAAAGACUUCUAUGACUUUGCUGUGUCUAAGGGUUUCUUUAAGGAAGGAAGUUCUGUUGAAUUAAAACACUUCUUCUUUGCUCAGGAUGGUAAUGCUGCUAUCAGCGAUUAUGACUACUAUCGUUAUAAUCUACCAACAAUGUGUGAUAUCAGACAACUACUAUUUGUAGUUGAAGUUGUUGAUAAGUACUUUGAUUGUUACGAUGGUGGCUGUAUUAAUGCUAACCAAGUCAUCGUCAACAACCUAGACAAAUCAGCUGGUUUUCCAUUUAAUAAAUGGGGUAAGGCUAGACUUUAUUAUGAUUCAAUGAGUUAUGAGGAUCAAGAUGCACUUUUCGCAUAUACAAAACGUAAUGUCAUCCCUACUAUAACUCAAAUGAAUCUUAAGUAUGCCAUUAGUGCAAAGAAUAGAGCUCGCACCGUAGCUGGUGUCUCUAUCUGUAGUACUAUGACCAAUAGACAGUUUCAUCAAAAAUUAUUGAAAUCAAUAGCCGCCACUAGAGGAGCUACUGUAGUAAUUGGAACAAGCAAAUUCUAUGGUGGUUGGCACAACAUGUUAAAAACUGUUUAUAGUGAUGUAGAAAACCCUCACCUUAUGGGUUGGGAUUAUCCUAAAUGUGAUAGAGCCAUGCCUAACAUGCUUAGAAUUAUGGCCUCACUUGUUCUUGCUCGCAAACAUACAACGUGUUGUAGCUUGUCACACCGUUUCUAUAGAUUAGCUAAUGAGUGUGCUCAAGUAUUGAGUGAAAUGGUCAUGUGUGGCGGUUCACUAUAUGUUAAACCAGGUGGAACCUCAUCAGGAGAUGCCACAACUGCUUAUGCUAAUAGUGUUUUUAACAUUUGUCAAGCUGUCACGGCCAAUGUUAAUGCACUUUUAUCUACUGAUGGUAACAAAAUUGCCGAUAAGUAUGUCCGCAAUUUACAACACAGACUUUAUGAGUGUCUCUAUAGAAAUAGAGAUGUUGACACAGACUUUGUGAAUGAGUUUUACGCAUAUUUGCGUAAACAUUUCUCAAUGAUGAUACUCUCUGACGAUGCUGUUGUGUGUUUCAAUAGCACUUAUGCAUCUCAAGGUCUAGUGGCUAGCAUAAAGAACUUUAAGUCAGUUCUUUAUUAUCAAAACAAUGUUUUUAUGUCUGAAGCAAAAUGUUGGACUGAGACUGACCUUACUAAAGGACCUCAUGAAUUUUGCUCUCAACAUACAAUGCUAGUUAAACAGGGUGAUGAUUAUGUGUACCUUCCUUACCCAGAUCCAUCAAGAAUCCUAGGGGCCGGCUGUUUUGUAGAUGAUAUCGUAAAAACAGAUGGUACACUUAUGAUUGAACGGUUCGUGUCUUUAGCUAUAGAUGCUUACCCACUUACUAAACAUCCUAAUCAGGAGUAUGCUGAUGUCUUUCAUUUGUACUUACAAUACAUAAGAAAGCUACAUGAUGAGUUAACAGGACACAUGUUAGACAUGUAUUCUGUUAUGCUUACUAAUGAUAACACUUCAAGGUAUUGGGAACCUGAGUUUUAUGAGGCUAUGUACACACCGCAUACAGUCUUACAGGCUGUUGGGGCUUGUGUUCUUUGCAAUUCACAGACUUCAUUAAGAUGUGGUGCUUGCAUACGUAGACCAUUCUUAUGUUGUAAAUGCUGUUACGACCAUGUCAUAUCAACAUCACAUAAAUUAGUCUUGUCUGUUAAUCCGUAUGUUUGCAAUGCUCCAGGUUGUGAUGUCACAGAUGUGACUCAACUUUACUUAGGAGGUAUGAGCUAUUAUUGUAAAUCACAUAAACCACCCAUUAGUUUUCCAUUGUGUGCUAAUGGACAAGUUUUUGGUUUAUAUAAAAAUACAUGUGUUGGUAGCGAUAAUGUUACUGACUUUAAUGCAAUUGCAACAUGUGACUGGACAAAUGCUGGUGAUUACAUUUUAGCUAACACCUGUACUGAAAGACUCAAGCUUUUUGCAGCAGAAACGCUCAAAGCUACUGAGGAGACAUUUAAACUGUCUUAUGGUAUUGCUACUGUACGUGAAGUGCUGUCUGACAGAGAAUUACAUCUUUCAUGGGAAGUUGGUAAACCUAGACCACCACUUAACCGAAAUUAUGUCUUUACUGGUUAUCGUGUAACUAAAAACAGUAAAGUACAAAUAGGAGAGUACACCUUUGAAAAAGGUGACUAUGGUGAUGCUGUUGUUUACCGAGGUACAACAACUUACAAAUUAAAUGUUGGUGAUUAUUUUGUGCUGACAUCACAUACAGUAAUGCCAUUAAGUGCACCUACACUAGUGCCACAAGAGCACUAUGUUAGAAUUACUGGCUUAUACCCAACACUCAAUAUCUCAGAUGAGUUUUCUAGCAAUGUUGCAAAUUAUCAAAAGGUUGGUAUGCAAAAGUAUUCUACACUCCAGGGACCACCUGGUACUGGUAAGAGUCAUUUUGCUAUUGGCCUAGCUCUCUACUACCCUUCUGCUCGCAUAGUGUAUACAGCUUGCUCUCAUGCCGCUGUUGAUGCACUAUGUGAGAAGGCAUUAAAAUAUUUGCCUAUAGAUAAAUGUAGUAGAAUUAUACCUGCACGUGCUCGUGUAGAGUGUUUUGAUAAAUUCAAAGUGAAUUCAACAUUAGAACAGUAUGUCUUUUGUACUGUAAAUGCAUUGCCUGAGACGACAGCAGAUAUAGUUGUCUUUGAUGAAAUUUCAAUGGCCACAAAUUAUGAUUUGAGUGUUGUCAAUGCCAGAUUACGUGCUAAGCACUAUGUGUACAUUGGCGACCCUGCUCAAUUACCUGCACCACGCACAUUGCUAACUAAGGGCACACUAGAACCAGAAUAUUUCAAUUCAGUGUGUAGACUUAUGAAAACUAUAGGUCCAGACAUGUUCCUCGGAACUUGUCGGCGUUGUCCUGCUGAAAUUGUUGACACUGUGAGUGCUUUGGUUUAUGAUAAUAAGCUUAAAGCACAUAAAGACAAAUCAGCUCAAUGCUUUAAAAUGUUUUAUAAGGGUGUUAUCACGCAUGAUGUUUCAUCUGCAAUUAACAGGCCACAAAUAGGCGUGGUAAGAGAAUUCCUUACACGUAACCCUGCUUGGAGAAAAGCUGUCUUUAUUUCACCUUAUAAUUCACAGAAUGCUGUAGCCUCAAAGAUUUUGGGACUACCAACUCAAACUGUUGAUUCAUCACAGGGCUCAGAAUAUGACUAUGUCAUAUUCACUCAAACCACUGAAACAGCUCACUCUUGUAAUGUAAACAGAUUUAAUGUUGCUAUUACCAGAGCAAAAGUAGGCAUACUUUGCAUAAUGUCUGAUAGAGACCUUUAUGACAAGUUGCAAUUUACAAGUCUUGAAAUUCCACGUAGGAAUGUGGCAACUUUACAAGCUGAAAAUGUAACAGGACUCUUUAAAGAUUGUAGUAAGGUAAUCACUGGGUUACAUCCUACACAGGCACCUACACACCUCAGUGUUGACACUAAAUUCAAAACUGAAGGUUUAUGUGUUGACAUACCUGGCAUACCUAAGGACAUGACCUAUAGAAGACUCAUCUCUAUGAUGGGUUUUAAAAUGAAUUAUCAAGUUAAUGGUUACCCUAACAUGUUUAUCACCCGCGAAGAAGCUAUAAGACAUGUACGUGCAUGGAUUGGCUUCGAUGUCGAGGGGUGUCAUGCUACUAGAGAAGCUGUUGGUACCAAUUUACCUUUACAGCUAGGUUUUUCUACAGGUGUUAACCUAGUUGCUGUACCUACAGGUUAUGUUGAUACACCUAAUAAUACAGAUUUUUCCAGAGUUAGUGCUAAACCACCGCCUGGAGAUCAAUUUAAACACCUCAUACCACUUAUGUACAAAGGACUUCCUUGGAAUGUAGUGCGUAUAAAGAUUGUACAAAUGUUAAGUGACACACUUAAAAAUCUCUCUGACAGAGUCGUAUUUGUCUUAUGGGCACAUGGCUUUGAGUUGACAUCUAUGAAGUAUUUUGUGAAAAUAGGACCUGAGCGCACCUGUUGUCUAUGUGAUAGACGUGCCACAUGCUUUUCCACUGCUUCAGACACUUAUGCCUGUUGGCAUCAUUCUAUUGGAUUUGAUUACGUCUAUAAUCCGUUUAUGAUUGAUGUUCAACAAUGGGGUUUUACAGGUAACCUACAAAGCAACCAUGAUCUGUAUUGUCAAGUCCAUGGUAAUGCACAUGUAGCUAGUUGUGAUGCAAUCAUGACUAGGUGUCUAGCUGUCCACGAGUGCUUUGUUAAGCGUGUUGACUGGACUAUUGAAUAUCCUAUAAUUGGUGAUGAACUGAAGAUUAAUGCGGCUUGUAGAAAGGUUCAACACAUGGUUGUUAAAGCUGCAUUAUUAGCAGACAAAUUCCCAGUUCUUCACGACAUUGGUAACCCUAAAGCUAUUAAGUGUGUACCUCAAGCUGAUGUAGAAUGGAAGUUCUAUGAUGCACAGCCUUGUAGUGACAAAGCUUAUAAAAUAGAAGAAUUAUUCUAUUCUUAUGCCACACAUUCUGACAAAUUCACAGAUGGUGUAUGCCUAUUUUGGAAUUGCAAUGUCGAUAGAUAUCCUGCUAAUUCCAUUGUUUGUAGAUUUGACACUAGAGUGCUAUCUAACCUUAACUUGCCUGGUUGUGAUGGUGGCAGUUUGUAUGUAAAUAAACAUGCAUUCCACACACCAGCUUUUGAUAAAAGUGCUUUUGUUAAUUUAAAACAAUUACCAUUUUUCUAUUACUCUGACAGUCCAUGUGAGUCUCAUGGAAAACAAGUAGUGUCAGAUAUAGAUUAUGUACCACUAAAGUCUGCUACGUGUAUAACACGUUGCAAUUUAGGUGGUGCUGUCUGUAGACAUCAUGCUAAUGAGUACAGAUUGUAUCUCGAUGCUUAUAACAUGAUGAUCUCAGCUGGCUUUAGCUUGUGGGUUUACAAACAAUUUGAUACUUAUAACCUCUGGAACACUUUUACAAGACUUCAGAGUUUAGAAAAUGUGGCUUUUAAUGUUGUAAAUAAGGGACACUUUGAUGGACAACAGGGUGAAGUACCAGUUUCUAUCAUUAAUAACACUGUUUACACAAAAGUUGAUGGUGUUGAUGUAGAAUUGUUUGAAAAUAAAACAACAUUACCUGUUAAUGUAGCAUUUGAGCUUUGGGCUAAGCGCAACAUUAAACCAGUACCAGAGGUGAAAAUACUCAAUAAUUUGGGUGUGGACAUUGCUGCUAAUACUGUGAUCUGGGACUACAAAAGAGAUGCUCCAGCACAUAUAUCUACUAUUGGUGUUUGUUCUAUGACUGACAUAGCCAAGAAACCAACUGAAACGAUUUGUGCACCACUCACUGUCUUUUUUGAUGGUAGAGUUGAUGGUCAAGUAGACUUAUUUAGAAAUGCCCGUAAUGGUGUUCUUAUUACAGAAGGUAGUGUUAAAGGUUUACAACCAUCUGUAGGUCCCAAACAAGCUAGUCUUAAUGGAGUCACAUUAAUUGGAGAAGCCGUAAAAACACAGUUCAAUUAUUAUAAGAAAGUUGAUGGUGUUGUCCAACAAUUACCUGAAACUUACUUUACUCAGAGUAGAAAUUUACAAGAAUUUAAACCCAGGAGUCAAAUGGAAAUUGAUUUCUUAGAAUUAGCUAUGGAUGAAUUCAUUGAACGGUAUAAAUUAGAAGGCUAUGCCUUCGAACAUAUCGUUUAUGGAGAUUUUAGUCAUAGUCAGUUAGGUGGUUUACAUCUACUGAUUGGACUAGCUAAACGUUUUAAGGAAUCACCUUUUGAAUUAGAAGAUUUUAUUCCUAUGGACAGUACAGUUAAAAACUAUUUCAUAACAGAUGCGCAAACAGGUUCAUCUAAGUGUGUGUGUUCUGUUAUUGAUUUAUUACUUGAUGAUUUUGUUGAAAUAAUAAAAUCCCAAGAUUUAUCUGUAGUUUCUAAGGUUGUCAAAGUGACUAUUGACUAUACAGAAAUUUCAUUUAUGCUUUGGUGUAAAGAUGGCCAUGUAGAAACAUUUUACCCAAAAUUACAAUCUAGUCAAGCGUGGCAACCGGGUGUUGCUAUGCCUAAUCUUUACAAAAUGCAAAGAAUGCUAUUAGAAAAGUGUGACCUUCAAAAUUAUGGUGAUAGUGCAACAUUACCUAAAGGCAUAAUGAUGAAUGUCGCAAAAUAUACUCAACUGUGUCAAUAUUUAAACACAUUAACAUUAGCUGUACCCUAUAAUAUGAGAGUUAUACAUUUUGGUGCUGGUUCUGAUAAAGGAGUUGCACCAGGUACAGCUGUUUUAAGACAGUGGUUGCCUACGGGUACGCUGCUUGUCGAUUCAGAUCUUAAUGACUUUGUCUCUGAUGCAGAUUCAACUUUGAUUGGUGAUUGUGCAACUGUACAUACAGCUAAUAAAUGGGAUCUCAUUAUUAGUGAUAUGUACGACCCUAAGACUAAAAAUGUUACAAAAGAAAAUGACUCUAAAGAGGGUUUUUUCACUUACAUUUGUGGGUUUAUACAACAAAAGCUAGCUCUUGGAGGUUCCGUGGCUAUAAAGAUAACAGAACAUUCUUGGAAUGCUGAUCUUUAUAAGCUCAUGGGACACUUCGCAUGGUGGACAGCCUUUGUUACUAAUGUGAAUGCGUCAUCAUCUGAAGCAUUUUUAAUUGGAUGUAAUUAUCUUGGCAAACCACGCGAACAAAUAGAUGGUUAUGUCAUGCAUGCAAAUUACAUAUUUUGGAGGAAUACAAAUCCAAUUCAGUUGUCUUCCUAUUCUUUAUUUGACAUGAGUAAAUUUCCCCUUAAAUUAAGGGGUACUGCUGUUAUGUCUUUAAAAGAAGGUCAAAUCAAUGAUAUGAUUUUAUCUCUUCUUAGUAAAGGUAGACUUAUAAUUAGAGAAAACAACAGAGUUGUUAUUUCUAGUGAUGUUCUUGUUAACAACUAAACGAACAAUGUUUGUUUUUCUUGUUUUAUUGCCACUAGUCUCUAGUCAGUGUGUUAAUCUUACAACCAGAACUCAAUUACCCCCUGCAUACACUAAUUCUUUCACACGUGGUGUUUAUUACCCUGACAAAGUUUUCAGAUCCUCAGUUUUACAUUCAACUCAGGACUUGUUCUUACCUUUCUUUUCCAAUGUUACUUGGUUCCAUGCUAUACAUGUCUCUGGGACCAAUGGUACUAAGAGGUUUGAUAACCCUGUCCUACCAUUUAAUGAUGGUGUUUAUUUUGCUUCCACUGAGAAGUCUAACAUAAUAAGAGGCUGGAUUUUUGGUACUACUUUAGAUUCGAAGACCCAGUCCCUACUUAUUGUUAAUAACGCUACUAAUGUUGUUAUUAAAGUCUGUGAAUUUCAAUUUUGUAAUGAUCCAUUUUUGGGUGUUUAUUACCACAAAAACAACAAAAGUUGGAUGGAAAGUGAGUUCAGAGUUUAUUCUAGUGCGAAUAAUUGCACUUUUGAAUAUGUCUCUCAGCCUUUUCUUAUGGACCUUGAAGGAAAACAGGGUAAUUUCAAAAAUCUUAGGGAAUUUGUGUUUAAGAAUAUUGAUGGUUAUUUUAAAAUAUAUUCUAAGCACACGCCUAUUAAUUUAGUGCGUGAUCUCCCUCAGGGUUUUUCGGCUUUAGAACCAUUGGUAGAUUUGCCAAUAGGUAUUAACAUCACUAGGUUUCAAACUUUACUUGCUUUACAUAGAAGUUAUUUGACUCCUGGUGAUUCUUCUUCAGGUUGGACAGCUGGUGCUGCAGCUUAUUAUGUGGGUUAUCUUCAACCUAGGACUUUUCUAUUAAAAUAUAAUGAAAAUGGAACCAUUACAGAUGCUGUAGACUGUGCACUUGACCCUCUCUCAGAAACAAAGUGUACGUUGAAAUCCUUCACUGUAGAAAAAGGAAUCUAUCAAACUUCUAACUUUAGAGUCCAACCAACAGAAUCUAUUGUUAGAUUUCCUAAUAUUACAAACUUGUGCCCUUUUGGUGAAGUUUUUAACGCCACCAGAUUUGCAUCUGUUUAUGCUUGGAACAGGAAGAGAAUCAGCAACUGUGUUGCUGAUUAUUCUGUCCUAUAUAAUUCCGCAUCAUUUUCCACUUUUAAGUGUUAUGGAGUGUCUCCUACUAAAUUAAAUGAUCUCUGCUUUACUAAUGUCUAUGCAGAUUCAUUUGUAAUUAGAGGUGAUGAAGUCAGACAAAUCGCUCCAGGGCAAACUGGAAAGAUUGCUGAUUAUAAUUAUAAAUUACCAGAUGAUUUUACAGGCUGCGUUAUAGCUUGGAAUUCUAACAAUCUUGAUUCUAAGGUUGGUGGUAAUUAUAAUUACCUGUAUAGAUUGUUUAGGAAGUCUAAUCUCAAACCUUUUGAGAGAGAUAUUUCAACUGAAAUCUAUCAGGCCGGUAGCACACCUUGUAAUGGUGUUGAAGGUUUUAAUUGUUACUUUCCUUUACAAUCAUAUGGUUUCCAACCCACUAAUGGUGUUGGUUACCAACCAUACAGAGUAGUAGUACUUUCUUUUGAACUUCUACAUGCACCAGCAACUGUUUGUGGACCUAAAAAGUCUACUAAUUUGGUUAAAAACAAAUGUGUCAAUUUCAACUUCAAUGGUUUAACAGGCACAGGUGUUCUUACUGAGUCUAACAAAAAGUUUCUGCCUUUCCAACAAUUUGGCAGAGACAUUGCUGACACUACUGAUGCUGUCCGUGAUCCACAGACACUUGAGAUUCUUGACAUUACACCAUGUUCUUUUGGUGGUGUCAGUGUUAUAACACCAGGAACAAAUACUUCUAACCAGGUUGCUGUUCUUUAUCAGGAUGUUAACUGCACAGAAGUCCCUGUUGCUAUUCAUGCAGAUCAACUUACUCCUACUUGGCGUGUUUAUUCUACAGGUUCUAAUGUUUUUCAAACACGUGCAGGCUGUUUAAUAGGGGCUGAACAUGUCAACAACUCAUAUGAGUGUGACAUACCCAUUGGUGCAGGUAUAUGCGCUAGUUAUCAGACUCAGACUAAUUCUCCUCGGCGGGCACGUAGUGUAGCUAGUCAAUCCAUCAUUGCCUACACUAUGUCACUUGGUGCAGAAAAUUCAGUUGCUUACUCUAAUAACUCUAUUGCCAUACCCACAAAUUUUACUAUUAGUGUUACCACAGAAAUUCUACCAGUGUCUAUGACCAAGACAUCAGUAGAUUGUACAAUGUACAUUUGUGGUGAUUCAACUGAAUGCAGCAAUCUUUUGUUGCAAUAUGGCAGUUUUUGUACACAAUUAAACCGUGCUUUAACUGGAAUAGCUGUUGAACAAGACAAAAACACCCAAGAAGUUUUUGCACAAGUCAAACAAAUUUACAAAACACCACCAAUUAAAGAUUUUGGUGGUUUUAAUUUUUCACAAAUAUUACCAGAUCCAUCAAAACCAAGCAAGAGGUCAUUUAUUGAAGAUCUACUUUUCAACAAAGUGACACUUGCAGAUGCUGGCUUCAUCAAACAAUAUGGUGAUUGCCUUGGUGAUAUUGCUGCUAGAGACCUCAUUUGUGCACAAAAGUUUAACGGCCUUACUGUUUUGCCACCUUUGCUCACAGAUGAAAUGAUUGCUCAAUACACUUCUGCACUGUUAGCGGGUACAAUCACUUCUGGUUGGACCUUUGGUGCAGGUGCUGCAUUACAAAUACCAUUUGCUAUGCAAAUGGCUUAUAGGUUUAAUGGUAUUGGAGUUACACAGAAUGUUCUCUAUGAGAACCAAAAAUUGAUUGCCAACCAAUUUAAUAGUGCUAUUGGCAAAAUUCAAGACUCACUUUCUUCCACAGCAAGUGCACUUGGAAAACUUCAAGAUGUGGUCAACCAAAAUGCACAAGCUUUAAACACGCUUGUUAAACAACUUAGCUCCAAUUUUGGUGCAAUUUCAAGUGUUUUAAAUGAUAUCCUUUCACGUCUUGACAAAGUUGAGGCUGAAGUGCAAAUUGAUAGGUUGAUCACAGGCAGACUUCAAAGUUUGCAGACAUAUGUGACUCAACAAUUAAUUAGAGCUGCAGAAAUCAGAGCUUCUGCUAAUCUUGCUGCUACUAAAAUGUCAGAGUGUGUACUUGGACAAUCAAAAAGAGUUGAUUUUUGUGGAAAGGGCUAUCAUCUUAUGUCCUUCCCUCAGUCAGCACCUCAUGGUGUAGUCUUCUUGCAUGUGACUUAUGUCCCUGCACAAGAAAAGAACUUCACAACUGCUCCUGCCAUUUGUCAUGAUGGAAAAGCACACUUUCCUCGUGAAGGUGUCUUUGUUUCAAAUGGCACACACUGGUUUGUAACACAAAGGAAUUUUUAUGAACCACAAAUCAUUACUACAGACAACACAUUUGUGUCUGGUAACUGUGAUGUUGUAAUAGGAAUUGUCAACAACACAGUUUAUGAUCCUUUGCAACCUGAAUUAGACUCAUUCAAGGAGGAGUUAGAUAAAUAUUUUAAGAAUCAUACAUCACCAGAUGUUGAUUUAGGUGACAUCUCUGGCAUUAAUGCUUCAGUUGUAAACAUUCAAAAAGAAAUUGACCGCCUCAAUGAGGUUGCCAAGAAUUUAAAUGAAUCUCUCAUCGAUCUCCAAGAACUUGGAAAGUAUGAGCAGUAUAUAAAAUGGCCAUGGUACAUUUGGCUAGGUUUUAUAGCUGGCUUGAUUGCCAUAGUAAUGGUGACAAUUAUGCUUUGCUGUAUGACCAGUUGCUGUAGUUGUCUCAAGGGCUGUUGUUCUUGUGGAUCCUGCUGCAAAUUUGAUGAAGACGACUCUGAGCCAGUGCUCAAAGGAGUCAAAUUACAUUACACAUAAACGAACUUAUGGAUUUGUUUAUGAGAAUCUUCACAAUUGGAACUGUAACUUUGAAGCAAGGUGAAAUCAAGGAUGCUACUCCUUCAGAUUUUGUUCGCGCUACUGCAACGAUACCGAUACAAGCCUCACUCCCUUUCGGAUGGCUUAUUGUUGGCGUUGCACUUCUUGCUGUUUUUCAGAGCGCUUCCAAAAUCAUAACCCUCAAAAAGAGAUGGCAACUAGCACUCUCCAAGGGUGUUCACUUUGUUUGCAACUUGCUGUUGUUGUUUGUAACAGUUUACUCACACCUUUUGCUCGUUGCUGCUGGCCUUGAAGCCCCUUUUCUCUAUCUUUAUGCUUUAGUCUACUUCUUGCAGAGUAUAAACUUUGUAAGAAUAAUAAUGAGGCUUUGGCUUUGCUGGAAAUGCCGUUCCAAAAACCCAUUACUUUAUGAUGCCAACUAUUUUCUUUGCUGGCAUACUAAUUGUUACGACUAUUGUAUACCUUACAAUAGUGUAACUUCUUCAAUUGUCAUUACUUCAGGUGAUGGCACAACAAGUCCUAUUUCUGAACAUGACUACCAGAUUGGUGGUUAUACUGAAAAAUGGGAAUCUGGAGUAAAAGACUGUGUUGUAUUACACAGUUACUUCACUUCAGACUAUUACCAGCUGUACUCAACUCAAUUGAGUACAGACACUGGUGUUGAACAUGUUACCUUCUUCAUCUACAAUAAAAUUGUUGAUGAGCCUGAAGAACAUGUCCAAAUUCACACAAUCGACGGUUCAUCCGGAGUUGUUAAUCCAGUAAUGGAACCAAUUUAUGAUGAACCGACGACGACUACUAGCGUGCCUUUGUAAGCACAAGCUGAUGAGUACGAACUUAUGUACUCAUUCGUUUCGGAAGAGACAGGUACGUUAAUAGUUAAUAGCGUACUUCUUUUUCUUGCUUUCGUGGUAUUCUUGCUAGUUACACUAGCCAUCCUUACUGCGCUUCGAUUGUGUGCGUACUGCUGCAAUAUUGUUAACGUGAGUCUUGUAAAACCUUCUUUUUACGUUUACUCUCGUGUUAAAAAUCUGAAUUCUUCUAGAGUUCCUGAUCUUCUGGUCUAAACGAACUAAAUAUUAUAUUAGUUUUUCUGUUUGGAACUUUAAUUUUAGCCAUGGCAGAUUCCAACGGUACUAUUACCGUUGAAGAGCUUAAAAAGCUCCUUGAACAAUGGAACCUAGUAAUAGGUUUCCUAUUCCUUACAUGGAUUUGUCUUCUACAAUUUGCCUAUGCCAACAGGAAUAGGUUUUUGUAUAUAAUUAAGUUAAUUUUCCUCUGGCUGUUAUGGCCAGUAACUUUAGCUUGUUUUGUGCUUGCUGCUGUUUACAGAAUAAAUUGGAUCACCGGUGGAAUUGCUAUCGCAAUGGCUUGUCUUGUAGGCUUGAUGUGGCUCAGCUACUUCAUUGCUUCUUUCAGACUGUUUGCGCGUACGCGUUCCAUGUGGUCAUUCAAUCCAGAAACUAACAUUCUUCUCAACGUGCCACUCCAUGGCACUAUUCUGACCAGACCGCUUCUAGAAAGUGAACUCGUAAUCGGAGCUGUGAUCCUUCGUGGACAUCUUCGUAUUGCUGGACACCAUCUAGGACGCUGUGACAUCAAGGACCUGCCUAAAGAAAUCACUGUUGCUACAUCACGAACGCUUUCUUAUUACAAAUUGGGAGCUUCGCAGCGUGUAGCAGGUGACUCAGGUUUUGCUGCAUACAGUCGCUACAGGAUUGGCAACUAUAAAUUAAACACAGACCAUUCCAGUAGCAGUGACAAUAUUGCUUUGCUUGUACAGUAAGUGACAACAGAUGUUUCAUCUCGUUGACUUUCAGGUUACUAUAGCAGAGAUAUUACUAAUUAUUAUGAGGACUUUUAAAGUUUCCAUUUGGAAUCUUGAUUACAUCAUAAACCUCAUAAUUAAAAAUUUAUCUAAGUCACUAACUGAGAAUAAAUAUUCUCAAUUAGAUGAAGAGCAACCAAUGGAGAUUGAUUAAACGAACAUGAAAAUUAUUCUUUUCUUGGCACUGAUAACACUCGCUACUUGUGAGCUUUAUCACUACCAAGAGUGUGUUAGAGGUACAACAGUACUUUUAAAAGAACCUUGCUCUUCUGGAACAUACGAGGGCAAUUCACCAUUUCAUCCUCUAGCUGAUAACAAAUUUGCACUGACUUGCUUUAGCACUCAAUUUGCUUUUGCUUGUCCUGACGGCGUAAAACACGUCUAUCAGUUACGUGCCAGAUCAGUUUCACCUAAACUGUUCAUCAGACAAGAGGAAGUUCAAGAACUUUACUCUCCAAUUUUUCUUAUUGUUGCGGCAAUAGUGUUUAUAACACUUUGCUUCACACUCAAAAGAAAGACAGAAUGAUUGAACUUUCAUUAAUUGACUUCUAUUUGUGCUUUUUAGCCUUUCUGCUAUUCCUUGUUUUAAUUAUGCUUAUUAUCUUUUGGUUCUCACUUGAACUGCAAGAUCAUAAUGAAACUUGUCACGCCUAAACGAACAUGAAAUUUCUUGUUUUCUUAGGAAUCAUCACAACUGUAGCUGCAUUUCACCAAGAAUGUAGUUUACAGUCAUGUACUCAACAUCAACCAUAUGUAGUUGAUGACCCGUGUCCUAUUCACUUCUAUUCUAAAUGGUAUAUUAGAGUAGGAGCUAGAAAAUCAGCACCUUUAAUUGAAUUGUGCGUGGAUGAGGCUGGUUCUAAAUCACCCAUUCAGUACAUCGAUAUCGGUAAUUAUACAGUUUCCUGUUUACCUUUUACAAUUAAUUGCCAGGAACCUAAAUUGGGUAGUCUUGUAGUGCGUUGUUCGUUCUAUGAAGACUUUUUAGAGUAUCAUGACGUUCGUGUUGUUUUAGAUUUCAUCUAAACGAACAAACUAAAAUGUCUGAUAAUGGACCCCAAAAUCAGCGAAAUGCACCCCGCAUUACGUUUGGUGGACCCUCAGAUUCAACUGGCAGUAACCAGAAUGGAGAACGCAGUGGGGCGCGAUCAAAACAACGUCGGCCCCAAGGUUUACCCAAUAAUACUGCGUCUUGGUUCACCGCUCUCACUCAACAUGGCAAGGAAGACCUUAAAUUCCCUCGAGGACAAGGCGUUCCAAUUAACACCAAUAGCAGUCCAGAUGACCAAAUUGGCUACUACCGAAGAGCUACCAGACGAAUUCGUGGUGGUGACGGUAAAAUGAAAGAUCUCAGUCCAAGAUGGUAUUUCUACUACCUAGGAACUGGGCCAGAAGCUGGACUUCCCUAUGGUGCUAACAAAGACGGCAUCAUAUGGGUUGCAACUGAGGGAGCCUUGAAUACACCAAAAGAUCACAUUGGCACCCGCAAUCCUGCUAACAAUGCUGCAAUCGUGCUACAACUUCCUCAAGGAACAACAUUGCCAAAAGGCUUCUACGCAGAAGGGAGCAGAGGCGGCAGUCAAGCCUCUUCUCGUUCCUCAUCACGUAGUCGCAACAGUUCAAGAAAUUCAACUCCAGGCAGCAGUAGGGGAACUUCUCCUGCUAGAAUGGCUGGCAAUGGCGGUGAUGCUGCUCUUGCUUUGCUGCUGCUUGACAGAUUGAACCAGCUUGAGAGCAAAAUGUCUGGUAAAGGCCAACAACAACAAGGCCAAACUGUCACUAAGAAAUCUGCUGCUGAGGCUUCUAAGAAGCCUCGGCAAAAACGUACUGCCACUAAAGCAUACAAUGUAACACAAGCUUUCGGCAGACGUGGUCCAGAACAAACCCAAGGAAAUUUUGGGGACCAGGAACUAAUCAGACAAGGAACUGAUUACAAACAUUGGCCGCAAAUUGCACAAUUUGCCCCCAGCGCUUCAGCGUUCUUCGGAAUGUCGCGCAUUGGCAUGGAAGUCACACCUUCGGGAACGUGGUUGACCUACACAGGUGCCAUCAAAUUGGAUGACAAAGAUCCAAAUUUCAAAGAUCAAGUCAUUUUGCUGAAUAAGCAUAUUGACGCAUACAAAACAUUCCCACCAACAGAGCCUAAAAAGGACAAAAAGAAGAAGGCUGAUGAAACUCAAGCCUUACCGCAGAGACAGAAGAAACAGCAAACUGUGACUCUUCUUCCUGCUGCAGAUUUGGAUGAUUUCUCCAAACAAUUGCAACAAUCCAUGAGCAGUGCUGACUCAACUCAGGCCUAAACUCAUGCAGACCACACAAGGCAGAUGGGCUAUAUAAACGUUUUCGCUUUUCCGUUUACGAUAUAUAGUCUACUCUUGUGCAGAAUGAAUUCUCGUAACUACAUAGCACAAGUAGAUGUAGUUAACUUUAAUCUCACAUAGCAAUCUUUAAUCAGUGUGUAACAUUAGGGAGGACUUGAAAGAGCCACCACAUUUUCACCGAGGCCACGCGGAGUACGAUCGAGUGUACAGUGAACAAUGCUAGGGAGAGCUGCCUAUAUGGAAGAGCCCUAAUGUGUAAAAUUAAUUUUAGUAGUGCUAUCCCCAUGUGAUUUUAAUAGCUUCUUAGGAGAAUGACAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");

    // Seq seq1(
    //     "seq1",
    //     "ugagccggcugggcgaucgcgacuuugcguaccacaugcgaugaacaugguggcgcaaggacgaggaaaguccggacuccacagagcacggugauuguuaacaacaaccc"
    //     "ggggugacccgcgggcaagugcaacagaaaguaaaccgccuagaauuuuucuagguaagggugaaacggugcgguaagagcgcaccagcgagguaggugacuaccucggc"
    //     "uagguaaaccccacugggagcaaggcauuagggcguaccgucguuucagacgguaugucugcacgaacgcuugaaggcugcucgccugaguucguggguagcugcuugag"
    //     "gcggccagugaugguuucguccagauggaugaucgccgcugaucuccgcuugucgggggugaguacagaauccggcuuauaugcuggcucauucg");

    // Seq seq1("seq1", "ggccaaguuuuuaagggcgcacgguggaugccuuggcaccaggaaccgaugaaggacgugggaggccacgauaguccccggggagccgucaaccaggcuuugauccggggguuuccgaauggggaaacccggcagucgucaugggcugucacccgcugcugaacacauaggcaguguggagggaacgcggggaagugaaacaucucaguacccgcaggaagagaaaacaaccgugauuccgggaguaguggcgagcgaaaccggaugaggccaaaccguauacgugugagacccggcagggguugcgugugcgggguugugggaucucucuuucacagucugccggcugugaggcgagucagaaaccguugauguaggcgaaggacaugcgaaagguccggcguagaggguaagacccccguagucgaaacaucagcggcucguuugagagacacccaaguagcacggggcccgagaaaucccgugugaaucuggcgggaccacccgcuaagccuaaauauucccuggugaccgauagcggauaguaccgugagggaauggugaaaaguaccgcgggagcggagugaaauaguaccugaaaccgugugccuacaagccgugggagcgucggacaucaagcuugcuuggugucucgugacugcgugccuuuugaagaaugagccugcgaguuugcgguguguugcgagguuaacccgaguggggaagccguagcgaaagcgaguccgaauagggcguuucaguagcacgcucaagacccgaagcggagugaucuagccaugggcagguugaagcggagguaagacuucguggaggaccgaacccaccaggguugaaaaccugggggaugaccugugguuaggggugaaaggccaaucaaacuccgugauagcugguucuccccgaaaugcauuuaggugcagcgucguguguuucuugccggagguagagcacuggauaggcgaugggcccuaccggguuacugaccuuagccaaacuccgaaugccgguaagugagagcgcggcagugagacugugggggauaagcuccauggucgagagggaaacagcccagagcaucgacuaaggccccuaagcguacgcuaagugggaaaggauguggagucgcacagacaaccaggagguuggcuuagaagcagccacccuugaaagagugcguaauagcucacuggucuagugauuccgcgccgacaauguagcggggcucaagcguaccgccgaagucgugucauucauacauuagggccaacgccuguauggauggguaggggagcgucgugugccgggugaagcagccgcggaagcgaguuguggacgguucacgagugagaaugcaggcaugaguagcgauacaaacgugagaaacguuugcgccgauugacuaaggguuccugggucaagcugaucugcccaggguaagucgggaccuaaggcgaggccgacaggcguagucgauggauaaccgguugauauuccgguacccgcugugaagcgucaaacaucgagcaucgugaugcuaaggccgugaagccgcccugaucucuucggaguugaggggagugguggagccgccggaccaagcgguuaguaggugagugauggggugacgcaggaagguaguccaucccggcgugguugucccgggguaagguguaggccgugcgguagguaaauccgucgcacacaaggcugagaccugaugccgagccgauuguggugaaguggaugauccuaugcugucgagaaaagccucuagcgaguuucauggcggcccguacccuaaaccgacucagguggucagguagagaauaccgaggcguucgggugaacuaugguuaaggaacucggcaaaaugcccccguaacuucgggagaaggggggccacaccuggugaugaucuuuacggucugagcuggggguggccgcagagaccagcgagaagcgacuguuuacuaaaaacacagguccgugcgaagccguaaggcgauguauacggacugacgccugcccggugcuggaacguuaaggggaccgguuagcuccauuucgguggggcgaagcugagaacuuaagcgccaguaaacggcggugguaacuauaaccauccuaagguagcgaaauuccuugucggguaaguuccgaccugcacgaauggcguaacgacuucucgacugucucaaccauaggcccggugaaauugcacuacgaguaaagaugcucguuucgcgcagcaggacggaaagaccccgggaccuuuacuacaguuugauauugguguucgguucggcuuguguaggauagcugggagacuuugaagcucgcacgccaguguggguggagucgucguugaaauaccagucuggucgugcuggaugucuaaccuggguccgugauccggaucagggacagugucugauggguaguuuaacuggggcgguugccuccuaaagaguaacggaggcgcccaaagguucccucagccugguuggcaaucagguguugaguguaagugcacaagggagcuugacugugagaccgacgggucgagcagggacgaaagucgggacuagugauccggcgguggcuuguggaagcgccgucgcucaacggauaaaagguaccccggggauaacaggcugaucuuccccaagaguccauaucgacgggaugguuuggcaccucgaugucggcucgucgcauccuggggcuggagucggucccaaggguugggcuguucgcccauuaaagcgguacgcgagcuggguuuagaacgucgugagacaguucggucccuauccgcugugcgcguaggagucuugagaagggcugucccuaguacgagaggaccgggacggacgaaccucuggugugccaguuguccugccaagggcauggcugguuggcuacguucgggagggauaaccgcugaaagcaucuaagcgggaagccugcuucgagaugaggacucccacccccuugagggguuaaggcucccaguagacgacuggguugauaggccggaucuggaagcaccgcaagguguggaggugaccgguacuaauaggccgagggcuuguccuc");

    // Seq seq1("seq1", "CCCAAAGGG");
    // Seq seq1("seq1",
    // "GCCGAGCCAGGUAGCGUUGGCUUGUCACCCGAGCGGGGGCAAUAAGGUGGUGUUGGAUGCCUGGUCGUUUGCGCUUGGGGUCUGCGCCUGUGGUUUGCACUAUGCGGCCCGCCCGUUCCAAGUUGCGUAGCGUGUGUGGGGCGCCUGGGCGAAGGCUCGAGCGUCCCUGCACCUAGAGUGGCGGGUAUUGCGUGAGGCUGGUUUCACAGAGCAGCGAGUACCGCCCGCUUCCAACGGUGGAAGGAUAACGGGCCGCUGCAGCCCUGGCCCGCUUCCGGCCCAAGUGCCUUCCAUGGCAGACCACCACCUUU");

    // Seq seq1("seq1", "AAAACGGUCCUUAUCAGGACCAAACA");

    // print the sequence
    seq1.set_encoding(nuc_encoding_scheme);
    InsideMode mode = InsideMode::PARTITION;
    Partition partition(&seq1, *(new EnergyModel(EnergyParamsType::VIENNA)), mode);
    partition.compute_inside();
    if (mode == InsideMode::PARTITION) {
        partition.compute_outside();
        partition.print_alpha_beta();
        // partition.calculate_prob_accm();
    }

    return 0;
}