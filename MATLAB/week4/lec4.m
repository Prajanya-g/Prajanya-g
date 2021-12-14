% the code tske in a wod and display some permutation of those letters 

word = input("Please enter the word: ",'s');
permutations = perms(word)
maxPerms = size(permutations, 1)
randPerm = randi(maxPerms);
disp(permutations(randPerm,:));
