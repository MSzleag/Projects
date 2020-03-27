using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameController : MonoBehaviour
{
    [SerializeField]
    private GameObject ballPrefab;

    //[SerializeField] we are not going with this today
    //private GameObject blockContainer;

    public List<Sprite> blockSprites;
    //we could just plug the sprites in in the inspector, but today we'll learn the Resources folder

    public float ballSpeed = 6f;
    //Just for the convenience, it's easier to adjust this in the scene than to browse the explorator

    public static GameController instance;
    //This will make the "instance" visible from all the other scripts without the need of initializing it.
    //Since this is our Gamecontroller, we will only have one active at the time anyways.

    private void Awake()
    {
        if(instance == null)
        {
            instance = this; //ok, explanations
        }
        else
        {
            Destroy(this.gameObject);
        }

        //blockSprites = ?, initialize the list
        //InitializeBlocks();
    }

    void Start()
    {
        SpawnBall();
    }

    public void SpawnBall()
    {
        //add the spawn logic
    }

    /* Could be done like that if we wanted to Spawn the blocks by code
     * could be useful if we wanted to make a game that works on all
     * types of resolutions (well it should I guess).
     * Also, foreach is a cool loop
    void InitializeBlocks()
    {
        //Spawn blocks here, maybe do some calculations with
        // Screen.width or Screen.height and then initialize
        foreach (Block block in blockContainer.GetComponentsInChildren<Block>())
        {
            //Here you could change the health or sth xD
        }
    }*/
}
