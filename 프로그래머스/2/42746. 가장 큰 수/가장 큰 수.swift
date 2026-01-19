import Foundation

func solution(_ numbers: [Int]) -> String {
    let strNums = numbers.map { String($0) }
    
    let sorted = strNums.sorted(by: { $0 + $1 > $1 + $0 })
    
    return sorted[0] == "0" ? "0" : sorted.joined()
}
