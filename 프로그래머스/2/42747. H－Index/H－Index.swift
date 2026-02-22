import Foundation

func solution(_ citations: [Int]) -> Int {
    let sorted = citations.sorted(by: >)
    
    var result = -1
    for (index, citation) in sorted.enumerated() {
        let paperIndex = index + 1
        
        if paperIndex > citation {
            result = index
            break
        }
    }
    
    if result == -1 {
        result = sorted.count
    }
    return result
}