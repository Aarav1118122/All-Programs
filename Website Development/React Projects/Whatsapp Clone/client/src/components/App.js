import React, { useState, useEffect } from "react";
import Login from "./Login";
import useLocalStorage from "../hooks/useLocalStorage";

function App() {
    const [id, setId] = useState();
    useEffect(() => {
        localStorage.setItem("whatsapp-clone", id);
    }, [id]);
    return (
        <>
            {id}
            <Login onIdSubmit={setId} />
        </>
    );
}

export default App;
