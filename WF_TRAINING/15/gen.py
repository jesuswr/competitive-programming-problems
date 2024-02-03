import random

def write_random_lines(file_path, n):
    options = ["1 0", "3 0"]
    with open(file_path, 'w') as file:
        file.write(str(n) + '\n')
        for _ in range(n):
            line = random.choice(options) + '\n'
            file.write(line)

if __name__ == "__main__":
    n = 300000  # Change this value to the number of lines you want to generate
    output_file = "inh"
    write_random_lines(output_file, n)
