wlength = 10;
dnaSequence = [length];
for i = 1 : length
   dnaSequence(i) = input("Please enter the DNA Sequence: ",'s'); 
   while (~(dnaSequence(i) == 'G' || dnaSequence(i) == 'T' || ...
           dnaSequence(i) == 'A' || dnaSequence(i) == 'C'))
       dnaSequence(i) = input("Wrong input enter again: ",'s'); 
   end
end

fprintf("Sequence\n");
for i = 1 : length
   fprintf("%c", dnaSequence(i));
end