using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SoundManager : MonoBehaviour {

    public static SoundManager instance;

    [SerializeField]
    private AudioSource gameStart, gameEnd, coindSound, jumpSound;

    void Awake() {
        if (instance == null)
            instance = this;
    }

    public void GameStartSound()
    {
        gameEnd.Play();
    }

    public void GameEndSound() {
        gameEnd.Play();
    }

    public void PickedUpCoin() {
        coindSound.Play();
    }

    public void JumpSound() {
        jumpSound.Play();
    }

} // class





































