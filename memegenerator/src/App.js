import React, { useState, useEffect } from 'react';
import Meme from "./meme";
import "./App.css"

const objtoquery = (obj) => {
 const values = Object.entries(obj).map(([key,value]) => `${key}=${value}`);
  return '?' + values.join('&');
}

function App() {
  const[templates,setTemplates]=useState([]);
  const[template,setTemplate]=useState(null);
  const[topText,setToptext]=useState("");
  const[bottomText,setBottomtext]=useState("");
  const[meme,setMeme]=useState(null);

  useEffect(() => {
    fetch("https://api.imgflip.com/get_memes").then( x => x.json().then(response => setTemplates(response.data.memes)));
  },[])
  
  if(meme){
    return(
      <div className="get">
        <img className="returnedimg"
         src={meme}
         alt="custom meme" />
      </div>
    )
  }


  return(
    <div>
    {template && (
      <form 
      onSubmit = {async e =>{
        e.preventDefault();
      const params ={
        template_id:template.id,
        text0:topText,
        text1:bottomText,
        username:"veeralsharma",
        password:"veeralsh"
      }
      const response= await fetch(`https://api.imgflip.com/caption_image${objtoquery(params)}`);
      const info = await response.json();
      setMeme(info.data.url);
      }}>
      <Meme  template={template} />
      <br />
      <input 
      type="text" 
      placeholder="text1"
      value={topText} 
      onChange={e => setToptext(e.target.value)} 
      />
      <input 
      type="text" 
      placeholder="text2"
      value={bottomText}
      onChange={e => setBottomtext(e.target.value)} />
      <button type="submit">create meme</button>
      </form>
      )}
      {!template &&(
        <>
        <h1>pick a meme template</h1>
      {templates.map(template => {
        return (
          <Meme
           template={template}
           onClick ={() => {
             setTemplate(template);
           }}
           />
        )
      })}
      </>
      )}
    </div>
  );
}

export default App;
