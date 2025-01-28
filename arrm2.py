def max_subarray_sum(arr):
    if not arr:
        return 0, -1, -1  # Если массив пустой, возвращаем 0 и индексы -1

    max_current = arr[0]
    max_global = arr[0]
    start = 0
    end = 0
    temp_start = 0  # Временный индекс начала подмассива

    for i in range(1, len(arr)):
        if arr[i] > max_current + arr[i]:
            max_current = arr[i]
            temp_start = i
        else:
            max_current += arr[i]

        # Обновляем max_global и индексы, только если нашли строго больший максимум
        if max_current > max_global:
            max_global = max_current
            start = temp_start
            end = i

    return max_global, start, end

print(max_subarray_sum([1, -2, 3, 4, 5]))