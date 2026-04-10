from typing import List

def k_most_frequent_strings(strs: List[str], k: int) -> List[str]:
    # Step 1: Count frequency manually
    freq = {}
    for s in strs:
        if s in freq:
            freq[s] += 1
        else:
            freq[s] = 1

    # Step 2: Sort based on (-frequency, string)
    sorted_items = sorted(freq.items(), key=lambda x: (-x[1], x[0]))

    # Step 3: Extract top k strings
    result = []
    for i in range(k):
        if i < len(sorted_items):
            result.append(sorted_items[i][0])

    return result
