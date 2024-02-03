def longest_increasing_subsequence(arr):
    n = len(arr)
    lis = [1] * n

    for i in range(1, n):
        for j in range(0, i):
            if arr[i] > arr[j] and lis[i] < lis[j] + 1:
                lis[i] = lis[j] + 1

    return max(lis)

sequence = [0, 0.841471, 0.909297, 0.14112, -0.756802, -0.958924, -0.279415, 0.656987, 0.989358, 0.412118, -0.544021, -0.99999, -0.536573, 0.420167, 0.990607]

result = longest_increasing_subsequence(sequence)
print(result)