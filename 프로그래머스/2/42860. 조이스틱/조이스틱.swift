import Foundation

func solution(_ name:String) -> Int {
    let aAscii: UInt8 = 65
    let zAscii: UInt8 = 90
    let name = name.map { $0 }
    
    // 수직 이동에 대한 최솟값
    var verticalMove = 0
    // 수평 이동에 대한 최솟값
    // - 한 방향으로만 갈 때 = 문자열 길이 - 1
    var horizontalMove = name.count - 1
    for i in 0..<name.count {
        // 수직 이동에 대한 최솟값 계산
        let charAscii = name[i].asciiValue!
        let dist = min(charAscii - aAscii, zAscii + 1 - charAscii)
        verticalMove += Int(dist)
        
        // 연속된 A의 끝을 계산
        var aEndIndex = i + 1
        while aEndIndex < name.count && name[aEndIndex] == "A" {
            aEndIndex += 1
        }
        
        // 문자열 끝부터 연속된 A 중 마지막 인덱스까지의 거리
        let aEndDistFromLast = name.count - aEndIndex
        // 시작점[0]에서 연속된 A 끝 뒤로 이동(왼쪽) ➡️ 다시 시작점[0]으로 돌아감(오른쪽) ➡️ 시작점[0]에서 연속된 A 시작 전까지 이동(오른쪽)
        let backAndForward = aEndDistFromLast * 2 + i
        // 시작점[0]에서 연속된 A 시작 전까지 이동(오른쪽) ➡️ 다시 시작점[0]으로 돌아감(왼쪽) ➡️ 시작점[0]에서 연속된 A 끝 뒤로 이동(왼쪽)
        let forwardAndBack = i * 2 + aEndDistFromLast
        horizontalMove = min(horizontalMove, backAndForward, forwardAndBack)
    }
    
    return verticalMove + horizontalMove
}
