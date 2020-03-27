using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Block : MonoBehaviour
{
    public int health;
    private SpriteRenderer blockSprite; //we wanna change our sprite

    private void Awake()
    {
        blockSprite = GetComponentInChildren<SpriteRenderer>();
    }

    private void Start()
    {
        UpdateSprite(); //get the right color
    }

    private void UpdateSprite()
    {
        blockSprite.sprite = GameController.instance.blockSprites[health-1];
        //Gamecontroller holds these in a List, so the number in [] has to be -1
        //That's because our numbers are 3->2->1, and the List elements have numbers 2->1->0
    }

    public void TakeDamage()
    {
        health--; //same as health = health - 1; or health -= 1;
        //what now?

    }

    private void Die()
    {
        //additional place for some extra stuff if needed, i dunno lol
        Destroy(this.gameObject);
    }
}
