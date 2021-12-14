function updated_sequence = remove_nucleotide(dna_sequence, nucleotide)
    count = 1;
    updated_sequence = [];
    for i = 1 : length(dna_sequence)
        if(dna_sequence(i) ~= nucleotide)
            updated_sequence(count) = dna_sequence(i);
            count  = count + 1;
    end
end