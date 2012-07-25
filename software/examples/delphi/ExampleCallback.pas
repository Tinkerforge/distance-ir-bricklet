program ExampleCallback;

{$ifdef MSWINDOWS}{$apptype CONSOLE}{$endif}
{$ifdef FPC}{$mode OBJFPC}{$H+}{$endif}

uses
  SysUtils, IPConnection, BrickletDistanceIR;

type
  TExample = class
  private
    ipcon: TIPConnection;
    dr: TBrickletDistanceIR;
  public
    procedure DistanceCB(const distance: word);
    procedure Execute;
  end;

const
  HOST = 'localhost';
  PORT = 4223;
  UID = '6Vw';

var
  e: TExample;

{ Callback function for distance callback (parameter has unit mm) }
procedure TExample.DistanceCB(const distance: word);
begin
  WriteLn(Format('Distance: %f cm', [distance/10.0]));
end;

procedure TExample.Execute;
begin
  { Create IP connection to brickd }
  ipcon := TIPConnection.Create(HOST, PORT);

  { Create device object }
  dr := TBrickletDistanceIR.Create(UID);

  { Add device to IP connection }
  ipcon.AddDevice(dr);
  { Don't use device before it is added to a connection }

  { Set Period for distance callback to 0.2s (200ms)
    Note: The callback is only called every 200ms if the
          distance has changed since the last call! }
  dr.SetDistanceCallbackPeriod(200);

  { Register distance callback to procedure DistanceCB }
  dr.OnDistance := {$ifdef FPC}@{$endif}DistanceCB;

  WriteLn('Press key to exit');
  ReadLn;
  ipcon.Destroy;
end;

begin
  e := TExample.Create;
  e.Execute;
  e.Destroy;
end.
