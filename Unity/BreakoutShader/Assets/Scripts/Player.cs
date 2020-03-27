using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{ //pretty much same stuff here
    private Rigidbody2D playerBody;
    public float speed = 5.0f;

    void Start()
    {
        playerBody = GetComponent<Rigidbody2D>();
    }

    void FixedUpdate()
    {
        float h = Input.GetAxis("Horizontal");
        playerBody.velocity = new Vector2(h * speed, 0.0f);
    }
}
