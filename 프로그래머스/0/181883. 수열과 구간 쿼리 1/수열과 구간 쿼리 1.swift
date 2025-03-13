import Foundation

func solution(_ arr:[Int], _ queries:[[Int]]) -> [Int] {
    var answer = arr
    
    for i in 0..<queries.count {
        let s = queries[i][0]
        let e = queries[i][1]
        for j in s...e {
            answer[j] += 1
        }
    }
    
    return answer
}