length = 10;
guanine = 0;
adenine = 0;
cytosine = 0;
thymine = 0;


dnaSequence = [length];
for i = 1 : length
    dnaSequence(i) = input("Please enter the DNA Sequence: ",'s');
    while (~(dnaSequence(i) == 'G' || dnaSequence(i) == 'T' || ...
            dnaSequence(i) == 'A' || dnaSequence(i) == 'C'))
        dnaSequence(i) = input("Wrong input enter again: ",'s');
    end
    if (dnaSequence(i) == 'G')
        guanine = guanine + 1;
        
    elseif(dnaSequence(i) == 'T')
        adenine = adenine + 1;
        
    elseif( dnaSequence(i) == 'A' )
        cytosine = cytosine + 1;
        
    else
        thymine = thymine + 1;
    end
end

fprintf("Sequence\n");
for i = 1 : length
    fprintf("%c", dnaSequence(i));
end

fprintf("\n");
fprintf("%d guanine\n", guanine);
fprintf("%d adenine\n",adenine);
fprintf("%d cytosine\n", cytosine);
fprintf("%d thymine\n", thymine);