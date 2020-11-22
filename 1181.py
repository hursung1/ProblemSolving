def word_quicksort(word_list):
    pivot = 0
    low = 1
    high = len(word_list) - 1 
    
    pass
    return

N = int(input())
word_list = []
word_dict = {}
max_len = 0

for i in range(N):
    input_word = input()
    word_len = len(input_word)
    if word_len > max_len:
        max_len = word_len

    if word_len not in word_dict.keys():
        word_dict[word_len] = []
    
    if input_word not in word_dict[word_len]:
        word_dict[word_len].append(input_word)

for key in range(max_len+1):
    if key in word_dict.keys(): 
        value = word_dict[key]
        for w in sorted(value):
            print(w)
