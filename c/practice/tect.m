dnaInput = input("Please enter the DNA Sequence: ",'s'); 
dnaSequence = char(dnaInput);
dnaSequence = dnaSequence(1:10);
for i = 1 : length(dnaSequence)
   while (~(dnaSequence(i) == 'G' || dnaSequence(i) == 'T' || ...
           dnaSequence(i) == 'A' || dnaSequence(i) == 'C'))
       dnaSequence(i) = input("Wrong input enter again: ",'s'); 
   end
end