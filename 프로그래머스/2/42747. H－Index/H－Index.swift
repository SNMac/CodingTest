import Foundation

func solution(_ citations: [Int]) -> Int {
    let sorted = citations.sorted(by: >)
    
    var result = -1
    for (index, citation) in sorted.enumerated() {
        let paperIndex = index + 1
        
        // paperIndex(index + 1)가 citation보다 커지기 시작할 때
        // => 그 직전 paperIndex(index)가 H-Index
        if paperIndex > citation {
            result = index
            break
        }
    }
    
    // result가 변경되지 않은 경우
    // => 발표된 논문 모두 citation이 paperIndex보다 크므로 논문 개수가 H-Index
    if result == -1 {
        result = sorted.count
    }
    return result
}
