% array of numbers
A = [1 2 3 4];
B = []
%changing to absolute value 
for  i = 1 : length(A)
  B(i) = 0;
  for j = 1 : i 
      B(i) = B(i) + A(j);
  end
end

% display result
disp(B);

