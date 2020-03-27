using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Jump : MonoBehaviour
{
    private bool jumpRequest = false;
    [SerializeField]
    private float velocity = 10.0f;
    [SerializeField]
    private float fallMultiplier = 2.5f;
    [SerializeField]
    private float lowJumpMultiplier = 2.0f;

    private Rigidbody rigidBody;
    private void Awake()
    {
        rigidBody = GetComponent<Rigidbody>();
    }

    // Update is called once per frame
    void Update()
    {
     if (Input.GetButton("Jump")) { jumpRequest = true; }   
    }
    private void FixedUpdate(){
        if (jumpRequest)
        {
            rigidBody.AddForce(Vector3.up * velocity, 
                ForceMode.Impulse);
            jumpRequest = false;
        }
        if(rigidBody.velocity.y < 0.0f)
        {
            rigidBody.velocity += Vector3.up * Physics.gravity.y * (fallMultiplier - 1)*Time.fixedDeltaTime;
        }
        else if (rigidBody.velocity.y > 0 && !Input.GetButton("Jump"))
        {
            rigidBody.velocity += Vector3.up * Physics.gravity.y * (lowJumpMultiplier - 1)*Time.fixedDeltaTime;
        }
        
    }
}
