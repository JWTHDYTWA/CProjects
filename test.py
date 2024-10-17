def count_progressions(L, R, K):
    def count_up_to(n):
        return sum((n - i) // K for i in range(1, K))

    total = 0
    for d in range(1, (R - L) // (K - 1) + 1):
        right = min((R - L) // d + 1, K)
        left = max((L - 1) // d + 1, 1)
        if right > left:
            total += count_up_to(right) - count_up_to(left)

    return total

# Чтение входных данных
with open('input.txt', 'r') as f:
    L, R, K = map(int, f.read().split())

# Вычисление результата
result = count_progressions(L, R, K)

# Запись результата
with open('output.txt', 'w') as f:
    f.write(str(result))