import Foundation

func solution(_ numbers: [Int]) -> String {
    let numStrArr: [String] = numbers.map { String($0) }
    
    let sorted = numStrArr.sorted { $0 + $1 > $1 + $0 }
    
    return sorted[0] == "0" ? "0" : sorted.reduce("", +)
}
