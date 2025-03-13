import Foundation

func solution(_ arr:[Int], _ queries:[[Int]]) -> [Int] {
    var answer = [Int](repeating: 1_000_001, count: queries.count)
    
    for i in 0..<queries.count {
        let s = queries[i][0]
        let e = queries[i][1]
        let k = queries[i][2]
        
        for j in s...e {
            if arr[j] > k && arr[j] < answer[i] {
                answer[i] = arr[j]
            }
        }
        if answer[i] == 1_000_001 {
            answer[i] = -1
        }
    }
    
    return answer
}