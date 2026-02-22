import Foundation

func solution(_ answers:[Int]) -> [Int] {
    
    let firstSupo = [1, 2, 3, 4, 5]
    let secondSupo = [2, 1, 2, 3, 2, 4, 2, 5]
    let thirdSupo = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    
    var firstSupoScore = 0
    var secondSupoScore = 0
    var thirdSupoScore = 0
    for (index, answer) in answers.enumerated() {
        let fisrtSupoIndex = index % firstSupo.count
        let secondSupoIndex = index % secondSupo.count
        let thirdSupoIndex = index % thirdSupo.count
        
        if firstSupo[fisrtSupoIndex] == answer {
            firstSupoScore += 1
        }
        if secondSupo[secondSupoIndex] == answer {
            secondSupoScore += 1
        }
        if thirdSupo[thirdSupoIndex] == answer {
            thirdSupoScore += 1
        }
    }
    
    let maxScore = [firstSupoScore, secondSupoScore, thirdSupoScore].max()!
    if maxScore == 0 {
        return []
    }
    
    let totalScores = [(1, firstSupoScore), (2, secondSupoScore), (3, thirdSupoScore)]
    var result = totalScores
                    .filter({ $0.1 == maxScore })
                    .map({ $0.0 })
    return result
}