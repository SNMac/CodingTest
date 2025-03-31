import Foundation

func solution(_ brown:Int, _ yellow:Int) -> [Int] {
    var answer = [Int]()
    
    // 노란색 격자 가로
    for yVrtc in 1...Int(sqrt(Double(yellow))) {
        // 노란색 격자 세로
        let yHriz = yellow / yVrtc
        if yellow % yHriz != 0 {
            continue
        }
        
        let carpetHriz = yHriz + 2
        let carpetVrtc = yVrtc + 2
        
        // 갈색 격자 맨 위아래 넓이
        let bTopBottom = carpetHriz * 2
        // 갈색 격자 양쪽 한칸씩 있는 넓이
        let bBothSides = yVrtc * 2
        // 갈색 격자 넓이
        let bArea = bTopBottom + bBothSides
        if bArea == brown {
            answer = [carpetHriz, carpetVrtc]
            break
        }
    }
    return answer
}