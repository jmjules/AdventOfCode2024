import re

def test_solution(file_name: str):
      with open(file_name + ".txt") as input:
            letter_A_indices = []
            grid = []

            for y, row in enumerate(input):
                  temp_row = []
                  for x, letter in enumerate(row):
                        temp_row.append(letter)
                        if letter == 'A':
                              letter_A_indices.append([y, x])
                  grid.append(temp_row)
            
            check_crosses(grid, letter_A_indices)
            
            
def check_crosses(grid, indices):
      sum = 0
      
      for spot in indices:
            if check_diag(grid, spot):
                  sum += 1

      print(sum)


def check_diag(grid, spot):
      y = spot[0]
      x = spot[1]
      if y > 0 and x > 0 and y < len(grid) - 1 and x < len(grid[0]) - 1:
            tl = grid[y - 1][x - 1]
            tr = grid[y - 1][x + 1]
            bl = grid[y + 1][x - 1]
            br = grid[y + 1][x + 1]

            test_diag = tl + 'A' + br
            test_antidiag = tr + 'A' + bl
            diag = False
            antidiag = False
            if test_diag == 'MAS' or test_diag == 'SAM':
                  diag = True
            if test_antidiag == 'MAS' or test_antidiag == 'SAM':
                  antidiag = True

            if diag and antidiag:
                  return True
            
      return False








# test_solution("example")
test_solution("input")