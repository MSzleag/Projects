using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Ball : MonoBehaviour
{
    private float speed;
    private Rigidbody2D ballBody;

    private void Start()
    {
        speed = GameController.instance.ballSpeed;  //pretty much for the convenience of changing it through
                                                    //the GameControllers Inspector
        ballBody = GetComponent<Rigidbody2D>();
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.collider.CompareTag("Block"))
        {//if we hit a block, make it take the hit
            collision.collider.GetComponent<Block>().TakeDamage(); //get component could return a null, but we made sure we hit a block
        }
        else if (collision.collider.CompareTag("Player"))
        {//if we hit a player, bounce accordingly to our position
            //float factor = hitFactor(); FILL IN THE ARGUMENTS
            //ballBody.velocity = new Vector2(factor, 1).normalized*speed;
        }
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {//what if we hit a trigger?
        if (collision.CompareTag("LowerBoundary"))
        {
            //What do we want to do?
        }
    }

    float hitFactor(Vector2 ballPos, Vector2 playerPos, float playerWidth)
    {
        //this helps calclate the relative position of two things
        return (ballPos.x - playerPos.x) / playerWidth;
    }
}
