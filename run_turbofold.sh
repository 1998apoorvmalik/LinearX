#!/bin/bash

# Hardcoded path to the turbofold executable
TURBOFOLD_EXEC="./tests/linearturbofold/main"

# Check if correct number of arguments are provided
if [ $# -ne 2 ]; then
    echo "Usage: $0 <input_directory> <output_directory>"
    exit 1
fi

# Input and output directories
input_dir=$1
output_dir=$2

# Check if the input directory exists
if [ ! -d "$input_dir" ]; then
    echo "Error: Input directory $input_dir does not exist!"
    exit 1
fi

# Create the output directory if it does not exist
if [ ! -d "$output_dir" ]; then
    mkdir -p "$output_dir"
fi

# Process each FASTA file in the input directory
for fasta_file in "$input_dir"/*.fasta; do
    # Check if any FASTA files are found
    if [ ! -e "$fasta_file" ]; then
        echo "No FASTA files found in directory $input_dir!"
        exit 1
    fi

    # Extract the base filename without the directory
    base_filename=$(basename "$fasta_file")

    # Initialize argument array for the executable
    args=()

    # Temporary variables for storing sequence name and sequence data
    seq_name=""
    seq_data=""

    # Read the FASTA file line by line
    while IFS= read -r line; do
        # If the line starts with '>', it's a sequence name
        if [[ "$line" == '>'* ]]; then
            # If seq_data is not empty, we already have a sequence to add
            if [ -n "$seq_data" ]; then
                args+=("$seq_name" "$seq_data")
                seq_data=""
            fi
            # Extract the sequence name (without the '>')
            seq_name="${line#>}"
        else
            # Append the line (sequence data) to seq_data
            seq_data="${seq_data}${line}"
        fi
    done < "$fasta_file"

    # Add the last sequence in the file
    if [ -n "$seq_data" ]; then
        args+=("$seq_name" "$seq_data")
    fi

    # Define the output file path in the output directory with .txt extension
    output_file="$output_dir/$base_filename.txt"

    # Run the turbofold executable and redirect the output to the output file
    echo "Processing $fasta_file..."
    "$TURBOFOLD_EXEC" "${args[@]}" > "$output_file"

    echo "Output written to $output_file"
done