% the code takes in input for a 3 x 3 vector and counts the odd fence values
% and displays it 

% declaring size 
sizeRow = 3;
sizeCol = 3; 
%counter
count  = 0;

% nested loop for row and and columns 
for row = [1 : sizeRow]
   for col = [1 : sizeCol]
       % getting input
      fprintf ("Enter the values for row %d, column %d", row , col);
      A(row,col) = input(": ");
      
      % counting the odd fence values 
      % counting every odd value in row 1 
      if ( row == 1)
          if (mod(A(row,col),2) == 1)
              count = count + 1;
          end
      % counting ever odd value in the last row
      elseif (row == sizeRow)
          if (mod(A(row,col),2) == 1)
              count = count + 1;
          end
      % count the first and last odd value in the middle rows 
      else
          if (mod(A(row,col),2) == 1 && col == 1 || col == sizeCol)
              count = count + 1;
          end
      end   
   end
end
% printing value
fprintf("There are %d odd values in the fence\n", count);
