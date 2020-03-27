using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Movement : MonoBehaviour
{
    [SerializeField] //modyfikacja z edytora i pierwszeństwo mają zmiany w edotyrze(inspektorze)
    private float speed = 5.0f;
    private Rigidbody rigidBody;
    private void Awake() //called before Start
    {
        rigidBody = GetComponent<Rigidbody>();
    }

    void Update()
    {
        float h = Input.GetAxis("Horizontal") 
            * speed * Time.deltaTime;
        float v = Input.GetAxis("Vertical") 
            * speed * Time.deltaTime;
        rigidBody.velocity = new Vector3(
            h,
            rigidBody.velocity.y,
           v);
    
    }
}
