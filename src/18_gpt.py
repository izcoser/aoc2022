import sys
# define a function to check if a given coordinate is in the list of cube coordinates
def is_adjacent(x, y, z, coords):
  for coord in coords:
    if coord[0] == x and coord[1] == y and coord[2] == z:
      return True
  return False

# define a function to count the number of uncovered sides for a given cube
def count_uncovered_sides(x, y, z, coords):
  uncovered_sides = 0
  # check if the side at (x+1,y,z) is not covered
  if not is_adjacent(x+1, y, z, coords):
    uncovered_sides += 1
  # check if the side at (x-1,y,z) is not covered
  if not is_adjacent(x-1, y, z, coords):
    uncovered_sides += 1
  # check if the side at (x,y+1,z) is not covered
  if not is_adjacent(x, y+1, z, coords):
    uncovered_sides += 1
  # check if the side at (x,y-1,z) is not covered
  if not is_adjacent(x, y-1, z, coords):
    uncovered_sides += 1
  # check if the side at (x,y,z+1) is not covered
  if not is_adjacent(x, y, z+1, coords):
    uncovered_sides += 1
  # check if the side at (x,y,z-1) is not covered
  if not is_adjacent(x, y, z-1, coords):
    uncovered_sides += 1
  return uncovered_sides

# read the input coordinates from the user
#coords_str = input("Enter the cube coordinates in the format 'x,y,z' (separated by newlines):\n")
coords_str = ''
for line in sys.stdin:
    coords_str += line
# split the input string into a list of strings, one for each coordinate
coords_str_list = coords_str.split("\n")
# create a list of tuples, each containing a single coordinate
coords = [(int(x), int(y), int(z)) for x, y, z in [coord_str.split(",") for coord_str in coords_str_list]]

# initialize a variable to keep track of the total number of uncovered sides
total_uncovered_sides = 0

# count the number of uncovered sides for each cube and add to the total
print(*coords, sep='\n')
for coord in coords:
  uncovered_sides = count_uncovered_sides(coord[0], coord[1], coord[2], coords)
  total_uncovered_sides += uncovered_sides

# print the total number of uncovered sides
print(f"The total number of uncovered sides is {total_uncovered_sides}.")