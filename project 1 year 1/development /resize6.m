% creatign vector 
a = [1,2,2,2,2;2,2,2,2,2;3,2,2,2,2;4,2,2,2,2;5,2,2,2,2;6,2,2,2,2;7,2,2,2,2];
% vector for which elements to double 
c = [2 1 2 1 2 1 2 ];
d = [2,1,2,1,2]
% doubling the elements
b = repelem(a,c,d)