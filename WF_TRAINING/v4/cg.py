import random
import string

# Define a function to generate random letters
def generate_random_letters():
    return ' '.join(random.choice(string.ascii_uppercase) for _ in range(3))

# Print 100 lines with 3 random letters separated by spaces
print(100)
for _ in range(100):
    random_letters = generate_random_letters()
    print(random_letters)
