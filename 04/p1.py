'''
MMMSXXMASM
MSAMXMSMSA
AMXSXMAAMM
MSAMASMSMX
XMASAMXAMM
XXAMMXXAMA
SMSMSASXSS
SAXAMASAAA
MAMMMXMMMM
MXMXAXMASX
==> 18 

- how many times does XMAS appear?
allowed:
-horizontal
-vertical
-diagonal
-backwards
-overlapping -> XMASAMX

idea:
-search all forward and backward with regex xmas && smax


'''

import re

grid = []

with open("input.txt") as input:
      for y, line in enumerate(input):
            grid.append([letter for letter in line.strip()])


def check_horizontal(test_grid: list):
      sum = 0
      pattern = re.compile(r'(?=(XMAS|SAMX))')

      for y, row in enumerate(test_grid):
            line = ''.join(row)
            matches = pattern.findall(line)
            match_count = len(matches)
            sum += match_count

      return sum

def check_vertical(test_grid: list):
      sum = 0
      pattern = re.compile(r'(?=(XMAS|SAMX))')

      for x, column in enumerate(zip(*test_grid)):
            line = ''.join(column)
            matches = pattern.findall(line)
            match_count = len(matches)
            sum += match_count 

      return sum


def check_diagonals(test_grid: list):
      diagonals = get_diagonals(test_grid)
      sum = 0
      pattern = re.compile(r'(?=(XMAS|SAMX))')

      for i, row in enumerate(diagonals):
            line = ''.join(row)
            matches = pattern.findall(line)
            match_count = len(matches)
            sum += match_count
      return sum

def get_diagonals(test_grid: list):
      rows = len(test_grid)
      cols = len(test_grid[0])
      diagonals = []

      for d in range(rows + cols -1):
            diag1 = []
            diag2 = []
            for i in range(rows):
                  j1 = d - i
                  j2 = cols - 1 - d + i
                  if 0 <= j1 < cols:
                        diag1.append(test_grid[i][j1])
                  if 0 <= j2 < cols:
                        diag2.append(test_grid[i][j2])
            if diag1:
                  diagonals.append(diag1)
            if diag2:
                  diagonals.append(diag2)
      return diagonals

end_sum = 0

end_sum += check_horizontal(grid)
end_sum += check_vertical(grid)
end_sum += check_diagonals(grid)

print(end_sum)


# print('h: '+ str(check_horizontal(grid)))
# print('v: '+ str(check_vertical(grid)))
# print('d: '+ str(check_diagonals(grid)))