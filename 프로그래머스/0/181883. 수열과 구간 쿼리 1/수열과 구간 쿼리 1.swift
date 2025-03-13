import Foundation

func solution(_ arr:[Int], _ queries:[[Int]]) -> [Int] {
    var answer = arr
    for i in queries {
        let start = i.first
        let end = i.last
        for j in start!...end! {
            answer[j] += 1
        }
    }
    
    return answer
}