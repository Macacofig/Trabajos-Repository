import { TenisGame } from "./TenisGame.js";

const startBtn = document.getElementById("start-btn");
const p1Btn = document.getElementById("p1-btn");
const p2Btn = document.getElementById("p2-btn");
const scoreDiv = document.getElementById("score");

let game = null;

p1Btn.disabled = true;
p2Btn.disabled = true;

startBtn.addEventListener("click", () => {
    game = new TenisGame();
    scoreDiv.innerHTML = game.showScore();

    startBtn.disabled = true;
    p1Btn.disabled = false;
    p2Btn.disabled = false;
});

p1Btn.addEventListener("click", () => {
    game.point("Player 1");
    updateView();
});

p2Btn.addEventListener("click", () => {
    game.point("Player 2");
    updateView();
});

function updateView() {
    const currentScore = game.showScore();
    scoreDiv.innerHTML = currentScore;

    if (
        currentScore === "Game For Player 1" ||
        currentScore === "Game For Player 2"
    ) {
        p1Btn.disabled = true;
        p2Btn.disabled = true;
        startBtn.disabled = false;
    }
}