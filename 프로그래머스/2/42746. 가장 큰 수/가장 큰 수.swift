import Foundation

func solution(_ numbers:[Int]) -> String {
    let sortedNumStr = numbers.map { String($0) }
        .sorted { $0 + $1 > $1 + $0 }
    
    if sortedNumStr.first == "0" { return "0" }
    return sortedNumStr.joined()
}
