% vector 
a = [1,2,2,2,2;2,2,2,2,2;3,2,2,2,2;4,2,2,2,2;5,2,2,2,2;6,2,2,2,2;7,2,2,2,2;];

%empting a row 
for row = [1:4]
    a(row,:) = [];
    disp(a);
end

% for row = [1:7]
%    disp(a(row)) 
% end