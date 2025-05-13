from fastapi import FastAPI
from fastapi.responses import FileResponse
from pydantic import BaseModel
from fastapi.middleware.cors import CORSMiddleware
app = FastAPI()
app.add_middleware(
 CORSMiddleware,
 allow_origins=["*"],
 allow_credentials=True,
 allow_methods=["*"],
 allow_headers=["*"],
)
# Store the latest GPS data
latest_gps = {"latitude": None, "longitude": None}
class GPSData(BaseModel):
 latitude: float
 longitude: float
@app.post("/gps")
async def receive_gps(data: GPSData):
 global latest_gps
 latest_gps = {"latitude": data.latitude, "longitude": data.longitude}
 return {"message": "GPS data received"}
@app.get("/gps/latest")
async def get_latest_gps():
 return latest_gps
@app.get("/")
async def serve_homepage():
 return FileResponse("index.html")