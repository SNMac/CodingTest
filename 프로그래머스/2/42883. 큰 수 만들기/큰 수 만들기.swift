import Foundation

func solution(_ number: String, _ k: Int) -> String {
    var stack: [Character] = []
    var deleteRemain = k
    
    for num in number {
        while deleteRemain != 0 && !stack.isEmpty && num > stack.last! {
            stack.removeLast()
            deleteRemain -= 1
        }
        
        stack.append(num)
    }
    
    return String(stack.prefix(stack.count - deleteRemain))
}
