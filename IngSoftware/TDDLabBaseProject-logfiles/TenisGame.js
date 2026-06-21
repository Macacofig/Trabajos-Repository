class TenisGame {
    constructor() {
        this.scorePlayer1 = "Love";
        this.scorePlayer2 = "Love";
    }

    showScore() {
        if (this.scorePlayer1 === "Game For Player 1") {
            return "Game For Player 1";
        }
        if (this.scorePlayer2 === "Game For Player 2") {
            return "Game For Player 2";
        }
        if (this.scorePlayer1 === "Advantage Player 1") {
            return "Advantage Player 1";
        }
        if (this.scorePlayer2 === "Advantage Player 2") {
            return "Advantage Player 2";
        }
        if (this.scorePlayer1 === "Deuce" && this.scorePlayer2 === "Deuce") {
            return "Deuce";
        }

        return `${this.scorePlayer1}-${this.scorePlayer2}`;
    }

    point(player) {

        if (player === "Player 1") {

            // Si estaban en Deuce
            if (this.scorePlayer1 === "Deuce") {
                this.scorePlayer1 = "Advantage Player 1";
                this.scorePlayer2 = "";
                return;
            }

            // Si tenía ventaja gana el juego
            if (this.scorePlayer1 === "Advantage Player 1") {
                this.scorePlayer1 = "Game For Player 1";
                return;
            }

            // Si el rival tenía ventaja vuelven a Deuce
            if (this.scorePlayer2 === "Advantage Player 2") {
                this.scorePlayer1 = "Deuce";
                this.scorePlayer2 = "Deuce";
                return;
            }

            // 40-30 -> Deuce
            if (this.scorePlayer1 === "30" && this.scorePlayer2 === "40") {
                this.scorePlayer1 = "Deuce";
                this.scorePlayer2 = "Deuce";
                return;
            }

            // 40 y rival < 40 -> gana
            if (this.scorePlayer1 === "40") {
                this.scorePlayer1 = "Game For Player 1";
                return;
            }

            this.scorePlayer1 = this.nextScore(this.scorePlayer1);
        }

        if (player === "Player 2") {

            if (this.scorePlayer2 === "Deuce") {
                this.scorePlayer2 = "Advantage Player 2";
                this.scorePlayer1 = "";
                return;
            }

            if (this.scorePlayer2 === "Advantage Player 2") {
                this.scorePlayer2 = "Game For Player 2";
                return;
            }

            if (this.scorePlayer1 === "Advantage Player 1") {
                this.scorePlayer1 = "Deuce";
                this.scorePlayer2 = "Deuce";
                return;
            }

            if (this.scorePlayer2 === "30" && this.scorePlayer1 === "40") {
                this.scorePlayer1 = "Deuce";
                this.scorePlayer2 = "Deuce";
                return;
            }

            if (this.scorePlayer2 === "40") {
                this.scorePlayer2 = "Game For Player 2";
                return;
            }

            this.scorePlayer2 = this.nextScore(this.scorePlayer2);
        }
    }

    nextScore(actualScore) {
        const scores = ["Love", "15", "30", "40"];
        const currentIndex = scores.indexOf(actualScore);
        return scores[currentIndex + 1];
    }
}

export { TenisGame };