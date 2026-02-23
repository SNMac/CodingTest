import Foundation

func solution(_ brown: Int, _ yellow: Int) -> [Int] {
    // 전체 영역 = 갈색 영역 + 노란색 영역
    // 노란색 영역 = (가로 - 2) * (세로 - 2)
    // 갈색 영역 = 가로 * 세로 - 노란색 영역
    
    var result: [Int] = []
    
    let area = brown + yellow
    var candidates: [[Int]] = []
    for h in 1...Int(sqrt(Double(area))) {
        if area % h == 0 {
            candidates.append([area / h, h])
        }
    }
    
    for candidate in candidates {
        let w = candidate[0]
        let h = candidate[1]
        
        let yellowArea = (w - 2) * (h - 2)
        let brownArea = w * h - yellowArea
        if brownArea == brown && yellowArea == yellow {
            result = [w, h]
            break
        }
    }
    
    return result
}
