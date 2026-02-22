import Foundation

func solution(_ array: [Int], _ commands: [[Int]]) -> [Int] {
    var result: [Int] = []
    for command in commands {
        let i = command[0] - 1
        let j = command[1] - 1
        let k = command[2] - 1
        
        let sliced = array[i...j]
        let sorted = Array(sliced).sorted()
        result.append(sorted[k])
    }
    
    return result
}
