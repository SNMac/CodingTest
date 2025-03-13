import Foundation

func solution(_ arr:[Int], _ queries:[[Int]]) -> [Int] {
    var answer = [Int](repeating: 1_000_001, count: queries.count)
    
    for (index, query) in queries.enumerated() {
        let s = query[0]
        let e = query[1]
        let k = query[2]
        
        for i in s...e {
            if arr[i] > k && arr[i] < answer[index] {
                answer[index] = arr[i]
            }
        }
        if answer[index] == 1_000_001 {
            answer[index] = -1
        }
    }
    
    return answer
}