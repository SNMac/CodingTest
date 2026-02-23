import Foundation

func solution(_ name: String) -> Int {
    var nameChar: [Character] = Array(name)
    
    var upDown = 0
    var leftRight = nameChar.count - 1
    
    func calcMove(_ char: Character) -> Int {
        // 위로 이동: char - 65
        // 아래로 이동: 91 - char
        let upMove = Int(char.asciiValue! - 65)
        let downMove = Int(91 - char.asciiValue!)
        return min(upMove, downMove)
    }
    
    for index in nameChar.indices {
        upDown += calcMove(nameChar[index])
        
        var endOfAIndex = index + 1
        while endOfAIndex < nameChar.count && nameChar[endOfAIndex] == "A" {
            endOfAIndex += 1
        }
        
        let leftMove = index * 2 + (nameChar.count - endOfAIndex)
        let rightMove = (nameChar.count - endOfAIndex) * 2 + index
        
        leftRight = min(leftRight, leftMove, rightMove)
    }
    
    return upDown + leftRight
}
