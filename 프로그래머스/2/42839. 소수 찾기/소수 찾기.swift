import Foundation

func isPrime(_ number: Int) -> Bool {
    if number < 4 {
        return number < 2 ? false : true
    }
    
    for i in 2...Int(sqrt(Double(number))) {
        if number % i == 0 { return false }
    }
    
    return true
}

func solution(_ numbers: String) -> Int {
    var numberSet: Set<Int> = []
    
    var visited: [Bool] = []
    func permutation(_ selectedNumArr: [String], _ selectedDigit: Int, _ targetDigit: Int) {
        if selectedDigit == targetDigit {
            let joined = selectedNumArr.joined()
            numberSet.insert(Int(joined)!)
            return
        }
        
        for (index, number) in numbers.enumerated() {
            if visited[index] { continue }
            
            var newSelectedNumArr = selectedNumArr
            newSelectedNumArr.append(String(number))
            
            visited[index] = true
            permutation(newSelectedNumArr, selectedDigit + 1, targetDigit)
            visited[index] = false
        }
    }
    
    for i in 1...numbers.count {
        visited = Array(repeating: false, count: numbers.count)
        permutation([], 0, i)
    }
    
    let primeNumbers = numberSet.filter { isPrime($0) }
    return primeNumbers.count
}