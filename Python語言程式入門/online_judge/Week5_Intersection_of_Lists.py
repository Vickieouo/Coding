T = int(input())
for t in range(T):
    nums1 = set(map(int, input().split()))
    nums2 = set(map(int, input().split()))
    print(f'Case #{t+1}: {sorted(nums1 & nums2)}')