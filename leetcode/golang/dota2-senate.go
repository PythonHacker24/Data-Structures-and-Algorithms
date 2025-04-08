func predictPartyVictory(senate string) string {
    radiant := []int{}
    dire := []int{}

    /* 
        Radiant and dire slices hold the position of party. 
        Since position is what matters in this case - to destroy and get destroyed
        For "RRDDR"
        radiant = [0, 1, 4]
        dire = [2, 3]
    */
    for i, party := range senate {
        if party == 'R' { 
            radiant = append(radiant, i) 
        } else {
            dire = append(dire, i)
        }
    }

    /*
        For "RRDDR"
        radiant = [0, 1, 4]
        dire = [2, 3]
        Now it's 0 vs 2 , the first index in the slice
        if radiant's position is close, favour radiant now and append it to the end of the queue
        vice versa for dire
        And since everyone want's to destroy the opposite party, remove the first in the queue. 
        In this example, our radiant party's 0 will go back in the slice while dire will have lost one senator. 
    */
    for len(radiant) > 0 && len(dire) > 0 {
        if radiant[0] < dire[0] {
            radiant = append(radiant, radiant[0] + len(senate))
        } else {
            dire = append(dire, dire[0] + len(senate))
        }

        radiant = radiant[1:]
        dire = dire[1:]
    }

    // Find out which party has survived  
    if len(radiant) > 0 {
        return "Radiant"
    } else {
        return "Dire"
    }
}
