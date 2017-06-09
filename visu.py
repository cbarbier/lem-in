import sys
import random
import time
import Tkinter as tk

def draw_node( canvas, x, y, color="#c3c3c3" , pos=0):
    if pos == -1:
        border = "#00ff00"
        color = "#00ff00"
    elif pos == 1:
        border = "#ff0000"
        color = "#ff0000"
    else:
        border = "#eeeeee"
    canvas.create_rectangle(x, y, x + 20, y + 20, outline=border, fill=color)
    
def draw_ant( canvas, x, y, color="#c3c3c3" ):
    canvas.create_rectangle(x + 5, y + 5, x + 15, y + 15, outline="#ffffff", fill=color)

def draw_line( canvas, n1, n2 , color="#cfcfcf" ):
    canvas.create_line(n1['x'] + 10, n1['y'] + 10, n2['x'] + 10, n2['y'] + 10, fill=color )

def get_ants():
    line = sys.stdin.readline()  
    try:
        nb = int(line)
    except ValueError:
        print "error"
        sys.exit()
    return nb

def update_max( lemin , x, y ):
    if ( x > lemin['maxx'] ):
        lemin['maxx'] = x
    if ( y > lemin['maxy'] ):
        lemin['maxy'] = y

def parser( lemin, nodes ):
    pos = 0
    for line in sys.stdin:
        if len ( line ) == 1:
            return
        if line[-1] == "\n":
            line = line[:-1]
        if line == "##start":
            pos = -1
            continue
        elif line == "##end":
            pos = 1
            continue
        elif line.startswith( '#' ):
            continue
        if '-' not in line:
            n, x, y = line.split()
            nodes[n] = {'name': n, 'links': []}
            nodes[n]['x'] = int(x)
            nodes[n]['y'] = int(y)
            update_max( lemin , nodes[n]['x'], nodes[n]['y'])
            nodes[n]['pos'] = pos
            if pos == -1:
                lemin['start'] = n
            elif pos == 1:
                lemin['end'] = n
            pos = 0
        else:
            n1, n2 = line.split('-')
            nodes[n1]['links'].append( n2 )
            nodes[n2]['links'].append( n1 )

def print_map( canvas, lemin ):
    tab = lemin['nodes'].values()
    for node in tab:
        draw_node( canvas, node['x'], node['y'] , "#c3c3c3", node['pos'])
        for link in node['links']:
            draw_line( canvas, node, lemin['nodes'][link] ) 
    canvas.pack()

def reset_canvas( canvas, lemin ):
    nodes = lemin['nodes'].values()
    for node in nodes:
        draw_node( canvas, node['x'], node['y'], "#c3c3c3" , node['pos'] )

def store_ants( lemin ):
    lemin['L'] = []
    for line in sys.stdin:
        if line == "\n":
            return
        lemin['L'].append( line )


def put_ants( canvas, lemin ):
    if len(lemin['L']) > 0:
        line = lemin['L'][0]
        lemin['L'] = lemin['L'][1:]
    else:
        sys.exit()
    ants = line.split(' ')
    lemin['ants'] = {}
    for ant in ants:
        n, r = ant[1:].split('-')
        if r[-1] == "\n":
            r = r[:-1]
        if n not in lemin['ants']:
            frm = lemin['start'] 
        else:
            frm = lemin['ants'][n][1]
        lemin['ants'][n] = [frm, r, lemin['colors'][int(n) % 8]]
        draw_ant( canvas, lemin['nodes'][r]['x'], lemin['nodes'][r]['y'], lemin['ants'][n][2] )
    canvas.after( 2000, put_ants, canvas, lemin )
    #canvas.pack()

def set_random_coord( lemin ):
    lemin['maxx'] = 800
    lemin['maxy'] = 800
    for node in lemin['nodes'].values():
        node['x'] = random.random() * lemin['maxx']
        node['y'] = random.random() * lemin['maxy']

def main ():

    #creating the window
    app = tk.Tk()
    app.title( "LEMIN by cbarbier" )

    #storing the data from ./lem-in output
    lemin = {'nodes': {}, 'maxx': 0, 'maxy': 0}
    lemin['colors'] = ["#d87373", "#eca162", "#33a99a", "#6648a1", "#db3882", "#ff3a3a", "#f2974a", "#6f0808"]
    lemin['nb_ants'] = get_ants()
    parser( lemin, lemin['nodes'] )
    if "-r" in sys.argv:
        set_random_coord( lemin )
    store_ants( lemin )
    canvas = tk.Canvas( app, height=lemin['maxx'] + 30, width=lemin['maxy'] + 30 )
    print_map( canvas, lemin )
    put_ants( canvas, lemin )
    app.mainloop()

main()
