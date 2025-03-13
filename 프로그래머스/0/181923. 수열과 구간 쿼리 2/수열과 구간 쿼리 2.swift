import Foundation

func solution(_ arr:[Int], _ queries:[[Int]]) -> [Int] {
    var answer = [Int](repeating: 1_000_001, count: queries.count)
    
    for (index, query) in queries.enumerated() {
        let s = query[0]
        let e = query[1]
        let k = query[2]
        
        for j in s...e {
            if arr[j] > k && arr[j] < answer[index] {
                answer[index] = arr[j]
            }
        }
        if answer[index] == 1_000_001 {
            answer[index] = -1
        }
    }
    
    return answer
}