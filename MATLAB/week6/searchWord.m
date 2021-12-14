function [ index ] = searchWord( dictionary, word )
%returns word's index if word is found in dict and false otherwise
% loop to look for dictionary entry
index=-1;
for i=[1:length(dictionary)]
    if (strcmp(word,dictionary(i))) % does the word match? 
        index=i;
    end
end
end