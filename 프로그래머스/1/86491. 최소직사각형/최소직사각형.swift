import Foundation

func solution(_ sizes: [[Int]]) -> Int {
    var cardWidth = -1
    var cardHeight = -1
    
    for size in sizes {
        let w = size[0]
        let h = size[1]
        
        if w < h {
            cardWidth = max(cardWidth, h)
            cardHeight = max(cardHeight, w)
        } else {
            cardWidth = max(cardWidth, w)
            cardHeight = max(cardHeight, h)
        }
    }
    
    return cardWidth * cardHeight
}